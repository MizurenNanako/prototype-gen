#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>
#include <errno.h>

#define STACKSIZE 1000000 // evaluation stack
#define FRAMESIZE 10000
#define BLOCKSIZE 100000
#define MAXBLOCKS 200
#define NSYM 100
#define INBUFSIZE 1000

#define JOURNALSIZE 1000

// MAXBLOCKS * BLOCKSIZE * sizeof (struct atom) = 480,000,000 bytes

// Symbolic expressions are built by linking structs of type "atom".
//
// For example, the expression "a b + c" is built like this:
//
//  _______      _______                                _______      _______
// |CONS   |    |CONS   |                              |CONS   |    |SYM    |
// |car cdr|--->|car cdr|----------------------------->|car cdr|--->|"nil"  |
// |_|_____|    |_|_____|                              |_|_____|    |_______|
//   |            |                                      |
//   |            |                                     _v_____
//   |            |                                    |SYM    |
//   |            |                                    |"c"    |
//   |            |                                    |_______|
//   |            |
//  _v_____      _v_____      _______      _______      _______
// |SYM    |    |CONS   |    |CONS   |    |CONS   |    |SYM    |
// |"add"  |    |car cdr|--->|car cdr|--->|car cdr|--->|"nil"  |
// |_______|    |_|_____|    |_|_____|    |_|_____|    |_______|
//                |            |            |
//               _v_____      _v_____      _v_____
//              |SYM    |    |SYM    |    |SYM    |
//              |"mul"  |    |"a"    |    |"b"    |
//              |_______|    |_______|    |_______|
//
// Programming notes:
//
// 1. Automatic C variables of type "struct atom *" should not be used.
//    Use the global variables p0-p9 instead.
//    Call save() before using p0-p9, then call restore() when finished.
//    The use of p0-p9 is required by the garbage collector.
//
// 2. Do not use NULL for a car or cdr.
//    Use the pointer returned by symbol(NIL) instead.
//    The code does not test for NULL.

struct atom {
	union {
		struct {
			struct atom *car;
			struct atom *cdr;
		} cons;
		struct {
			char *name;
			void (*func)(void);
		} ksym;
		struct {
			char *name;
			uint32_t index;
		} usym;
		struct {
			uint32_t *a; // rational number a over b
			uint32_t *b;
		} q;
		double d;
		char *str;
		struct tensor *tensor;
	} u;
	uint8_t k, tag, sign;
};

#define CONS		0
#define KSYM		1
#define USYM		2
#define RATIONAL	3
#define DOUBLE		4
#define STR		5
#define TENSOR		6

#define ABS		(0 * NSYM + 0)
#define ADJ		(0 * NSYM + 1)
#define AND		(0 * NSYM + 2)
#define ARCCOS		(0 * NSYM + 3)
#define ARCCOSH		(0 * NSYM + 4)
#define ARCSIN		(0 * NSYM + 5)
#define ARCSINH		(0 * NSYM + 6)
#define ARCTAN		(0 * NSYM + 7)
#define ARCTANH		(0 * NSYM + 8)
#define ARG		(0 * NSYM + 9)
#define ATOMIZE		(0 * NSYM + 10)

#define BESSELJ		(1 * NSYM + 0)
#define BESSELY		(1 * NSYM + 1)
#define BINDING		(1 * NSYM + 2)

#define C_UPPER		(2 * NSYM + 0)
#define C_LOWER		(2 * NSYM + 1)
#define CEILING		(2 * NSYM + 2)
#define CHECK		(2 * NSYM + 3)
#define CIRCEXP		(2 * NSYM + 4)
#define CLEAR		(2 * NSYM + 5)
#define CLOCK		(2 * NSYM + 6)
#define COEFF		(2 * NSYM + 7)
#define COFACTOR	(2 * NSYM + 8)
#define CONJ		(2 * NSYM + 9)
#define CONTRACT	(2 * NSYM + 10)
#define COS		(2 * NSYM + 11)
#define COSH		(2 * NSYM + 12)

#define D_UPPER		(3 * NSYM + 0)
#define D_LOWER		(3 * NSYM + 1)
#define DEFINT		(3 * NSYM + 2)
#define DEGREE		(3 * NSYM + 3)
#define DENOMINATOR	(3 * NSYM + 4)
#define DERIVATIVE	(3 * NSYM + 5)
#define DET		(3 * NSYM + 6)
#define DIM		(3 * NSYM + 7)
#define DO		(3 * NSYM + 8)
#define DOT		(3 * NSYM + 9)
#define DRAW		(3 * NSYM + 10)

#define EIGEN		(4 * NSYM + 0)
#define EIGENVAL	(4 * NSYM + 1)
#define EIGENVEC	(4 * NSYM + 2)
#define ERF		(4 * NSYM + 3)
#define ERFC		(4 * NSYM + 4)
#define EVAL		(4 * NSYM + 5)
#define EXIT		(4 * NSYM + 6)
#define EXP		(4 * NSYM + 7)
#define EXPAND		(4 * NSYM + 8)
#define EXPCOS		(4 * NSYM + 9)
#define EXPCOSH		(4 * NSYM + 10)
#define EXPSIN		(4 * NSYM + 11)
#define EXPSINH		(4 * NSYM + 12)
#define EXPTAN		(4 * NSYM + 13)
#define EXPTANH		(4 * NSYM + 14)

#define FACTOR		(5 * NSYM + 0)
#define FACTORIAL	(5 * NSYM + 1)
#define FILTER		(5 * NSYM + 2)
#define FLOATF		(5 * NSYM + 3)
#define FLOOR		(5 * NSYM + 4)
#define FOR		(5 * NSYM + 5)

#define GCD		(6 * NSYM + 0)

#define H_UPPER		(7 * NSYM + 0)
#define H_LOWER		(7 * NSYM + 1)
#define HADAMARD	(7 * NSYM + 2)

#define I_UPPER		(8 * NSYM + 0)
#define I_LOWER		(8 * NSYM + 1)
#define IMAG		(8 * NSYM + 2)
#define INFIXFORM	(8 * NSYM + 3)
#define INNER		(8 * NSYM + 4)
#define INTEGRAL	(8 * NSYM + 5)
#define INV		(8 * NSYM + 6)
#define ISPRIME		(8 * NSYM + 7)

#define J_UPPER		(9 * NSYM + 0)
#define J_LOWER		(9 * NSYM + 1)

#define KRONECKER	(10 * NSYM + 0)

#define LAST		(11 * NSYM + 0)
#define LATEX		(11 * NSYM + 1)
#define LCM		(11 * NSYM + 2)
#define LEADING		(11 * NSYM + 3)
#define LOG		(11 * NSYM + 4)

#define MAG		(12 * NSYM + 0)
#define MATHJAX		(12 * NSYM + 1)
#define MATHML		(12 * NSYM + 2)
#define MINOR		(12 * NSYM + 3)
#define MINORMATRIX	(12 * NSYM + 4)
#define MOD		(12 * NSYM + 5)

#define NIL		(13 * NSYM + 0)
#define NOEXPAND	(13 * NSYM + 1)
#define NOT		(13 * NSYM + 2)
#define NROOTS		(13 * NSYM + 3)
#define NUMBER		(13 * NSYM + 4)
#define NUMERATOR	(13 * NSYM + 5)

#define OR		(14 * NSYM + 0)
#define OUTER		(14 * NSYM + 1)

#define P_UPPER		(15 * NSYM + 0)
#define P_LOWER		(15 * NSYM + 1)
#define PI		(15 * NSYM + 2)
#define POLAR		(15 * NSYM + 3)
#define PREFIXFORM	(15 * NSYM + 4)
#define PRIME		(15 * NSYM + 5)
#define PRINT		(15 * NSYM + 6)
#define PRODUCT		(15 * NSYM + 7)

#define Q_UPPER		(16 * NSYM + 0)
#define Q_LOWER		(16 * NSYM + 1)
#define QUOTE		(16 * NSYM + 2)
#define QUOTIENT	(16 * NSYM + 3)

#define R_UPPER		(17 * NSYM + 0)
#define R_LOWER		(17 * NSYM + 1)
#define RANK		(17 * NSYM + 2)
#define RATIONALIZE	(17 * NSYM + 3)
#define REAL		(17 * NSYM + 4)
#define RECTF		(17 * NSYM + 5)
#define ROOTS		(17 * NSYM + 6)
#define ROTATE		(17 * NSYM + 7)
#define RUN		(17 * NSYM + 8)

#define S_UPPER		(18 * NSYM + 0)
#define S_LOWER		(18 * NSYM + 1)
#define SGN		(18 * NSYM + 2)
#define SIMPLIFY	(18 * NSYM + 3)
#define SIN		(18 * NSYM + 4)
#define SINH		(18 * NSYM + 5)
#define SQRT		(18 * NSYM + 6)
#define STATUS		(18 * NSYM + 7)
#define STOP		(18 * NSYM + 8)
#define SUBST		(18 * NSYM + 9)
#define SUM		(18 * NSYM + 10)

#define T_UPPER		(19 * NSYM + 0)
#define T_LOWER		(19 * NSYM + 1)
#define TAN		(19 * NSYM + 2)
#define TANH		(19 * NSYM + 3)
#define TEST		(19 * NSYM + 4)
#define TESTEQ		(19 * NSYM + 5)
#define TESTGE		(19 * NSYM + 6)
#define TESTGT		(19 * NSYM + 7)
#define TESTLE		(19 * NSYM + 8)
#define TESTLT		(19 * NSYM + 9)
#define TRACE		(19 * NSYM + 10)
#define TRANSPOSE	(19 * NSYM + 11)
#define TTY		(19 * NSYM + 12)

#define U_UPPER		(20 * NSYM + 0)
#define U_LOWER		(20 * NSYM + 1)
#define UNIT		(20 * NSYM + 2)

#define V_UPPER		(21 * NSYM + 0)
#define V_LOWER		(21 * NSYM + 1)

#define W_UPPER		(22 * NSYM + 0)
#define W_LOWER		(22 * NSYM + 1)

#define X_UPPER		(23 * NSYM + 0)
#define X_LOWER		(23 * NSYM + 1)

#define Y_UPPER		(24 * NSYM + 0)
#define Y_LOWER		(24 * NSYM + 1)

#define Z_UPPER		(25 * NSYM + 0)
#define Z_LOWER		(25 * NSYM + 1)
#define ZERO		(25 * NSYM + 2)

#define ADD		(26 * NSYM + 0)
#define MULTIPLY	(26 * NSYM + 1)
#define POWER		(26 * NSYM + 2)
#define INDEX		(26 * NSYM + 3)
#define SETQ		(26 * NSYM + 4)
#define EXP1		(26 * NSYM + 5)
#define SA		(26 * NSYM + 6)
#define SB		(26 * NSYM + 7)
#define SX		(26 * NSYM + 8)
#define ARG1		(26 * NSYM + 9)
#define ARG2		(26 * NSYM + 10)
#define ARG3		(26 * NSYM + 11)
#define ARG4		(26 * NSYM + 12)
#define ARG5		(26 * NSYM + 13)
#define ARG6		(26 * NSYM + 14)
#define ARG7		(26 * NSYM + 15)
#define ARG8		(26 * NSYM + 16)
#define ARG9		(26 * NSYM + 17)

#define MAXPRIMETAB 10000
#define MAXDIM 24

struct tensor {
	int ndim;
	int dim[MAXDIM];
	int nelem;
	struct atom *elem[1];
};

#define symbol(x) symtab[x]
#define push_symbol(x) push(symbol(x))
#define iscons(p) ((p)->k == CONS)
#define isrational(p) ((p)->k == RATIONAL)
#define isdouble(p) ((p)->k == DOUBLE)
#define isnum(p) (isrational(p) || isdouble(p))
#define isstr(p) ((p)->k == STR)
#define istensor(p) ((p)->k == TENSOR)
#define issymbol(p) ((p)->k == KSYM || (p)->k == USYM)
#define iskeyword(p) ((p)->k == KSYM)
#define isusersymbol(p) ((p)->k == USYM)

#define car(p) (iscons(p) ? (p)->u.cons.car : symbol(NIL))
#define cdr(p) (iscons(p) ? (p)->u.cons.cdr : symbol(NIL))
#define caar(p) car(car(p))
#define cadr(p) car(cdr(p))
#define cdar(p) cdr(car(p))
#define cddr(p) cdr(cdr(p))
#define caadr(p) car(car(cdr(p)))
#define caddr(p) car(cdr(cdr(p)))
#define cadar(p) car(cdr(car(p)))
#define cdadr(p) cdr(car(cdr(p)))
#define cddar(p) cdr(cdr(car(p)))
#define cdddr(p) cdr(cdr(cdr(p)))
#define caaddr(p) car(car(cdr(cdr(p))))
#define cadadr(p) car(cdr(car(cdr(p))))
#define caddar(p) car(cdr(cdr(car(p))))
#define cadddr(p) car(cdr(cdr(cdr(p))))
#define cdaddr(p) cdr(car(cdr(cdr(p))))
#define cddadr(p) cdr(cdr(car(cdr(p))))
#define cddddr(p) cdr(cdr(cdr(cdr(p))))
#define caddddr(p) car(cdr(cdr(cdr(cdr(p)))))
#define cadaddr(p) car(cdr(car(cdr(cdr(p)))))
#define cddaddr(p) cdr(cdr(car(cdr(cdr(p)))))
#define caddadr(p) car(cdr(cdr(car(cdr(p)))))
#define cdddaddr(p) cdr(cdr(cdr(car(cdr(cdr(p))))))
#define caddaddr(p) car(cdr(cdr(car(cdr(cdr(p))))))

#define ERR ((int) 0x80000000)

#define MPLUS 0
#define MMINUS 1
#define MLENGTH(p) (((int *) (p))[-1])
#define MZERO(p) (MLENGTH(p) == 1 && (p)[0] == 0)
#define MEQUAL(p, n) (MLENGTH(p) == 1 && (p)[0] == (n))

#define BLACK 0
#define BLUE 1
#define RED 2

#define Trace fprintf(stderr, "%s %d\n", __func__, __LINE__);

extern int primetab[MAXPRIMETAB];
