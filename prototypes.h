// ../eigenmath/src/abs.c :
void eval_abs(void);
void absfunc(void);
void absfunc_nib(void);
// ../eigenmath/src/add.c :
void eval_add(void);
void add(void);
void add_terms(int n);
void add_terms_nib(int n);
void flatten_terms(int h);
void combine_tensors(int h);
void add_tensors(void);
void combine_terms(int h);
int combine_terms_nib(int i, int j);
void sort_terms(int n);
int sort_terms_func(const void *q1, const void *q2);
int cmp_terms(struct atom *p1, struct atom *p2);
int is_imaginary_term(struct atom *p);
void add_numbers(void);
void add_rationals(void);
void add_integers(void);
void subtract(void);
// ../eigenmath/src/adj.c :
void eval_adj(void);
void adj(void);
void adj_nib(void);
// ../eigenmath/src/arccos.c :
void eval_arccos(void);
void arccos(void);
void arccos_nib(void);
// ../eigenmath/src/arccosh.c :
void eval_arccosh(void);
void arccosh(void);
void arccosh_nib(void);
// ../eigenmath/src/arcsin.c :
void eval_arcsin(void);
void arcsin(void);
void arcsin_nib(void);
// ../eigenmath/src/arcsinh.c :
void eval_arcsinh(void);
void arcsinh(void);
void arcsinh_nib(void);
// ../eigenmath/src/arctan.c :
void eval_arctan(void);
void arctan(void);
void arctan_nib(void);
void arctan_numerical_args(void);
// ../eigenmath/src/arctanh.c :
void eval_arctanh(void);
void arctanh(void);
void arctanh_nib(void);
// ../eigenmath/src/arg.c :
void eval_arg(void);
void arg(void);
void arg_nib(void);
void arg1(void);
void arg1_nib(void);
// ../eigenmath/src/atomize.c :
void eval_atomize(void);
void atomize(void);
// ../eigenmath/src/besselj.c :
void eval_besselj(void);
void besselj(void);
void besselj_nib(void);
// ../eigenmath/src/bessely.c :
void eval_bessely(void);
void bessely(void);
void bessely_nib(void);
// ../eigenmath/src/bignum.c :
void init_bignums(void);
void push_integer(int n);
void push_rational(int a, int b);
void push_rational_number(int sign, uint32_t *a, uint32_t *b);
int pop_integer(void);
void push_double(double d);
double pop_double(void);
int equaln(struct atom *p, int n);
int equalq(struct atom *p, int a, int b);
int cmpfunc(void);
int cmp_numbers(struct atom *p1, struct atom *p2);
int cmp_rationals(struct atom *a, struct atom *b);
double convert_rational_to_double(struct atom *p);
void convert_double_to_rational(double d);
void best_rational_approximation(double x);
void bignum_scan_integer(char *s);
void bignum_float(void);
void bignum_factorial(int n);
uint32_t * bignum_factorial_nib(int n);
void msetbit(uint32_t *x, uint32_t k);
void mclrbit(uint32_t *x, uint32_t k);
void mshiftright(uint32_t *a);
uint32_t * mscan(char *s);
char * mstr(uint32_t *u);
int mdivby1billion(uint32_t *u);
uint32_t * madd(uint32_t *u, uint32_t *v);
uint32_t * msub(uint32_t *u, uint32_t *v);
uint32_t * mmul(uint32_t *u, uint32_t *v);
uint32_t * mdiv(uint32_t *u, uint32_t *v);
uint32_t * mmod(uint32_t *u, uint32_t *v);
uint32_t * mpow(uint32_t *u, uint32_t *v);
void mshr(uint32_t *u);
int mcmp(uint32_t *u, uint32_t *v);
int meq(uint32_t *u, uint32_t *v);
uint32_t * mint(uint32_t n);
uint32_t * mnew(int n);
void mfree(uint32_t *u);
uint32_t * mcopy(uint32_t *u);
void mnorm(uint32_t *u);
uint32_t * mgcd(uint32_t *u, uint32_t *v);
uint32_t * mmodpow(uint32_t *x, uint32_t *n, uint32_t *m);
uint32_t * mroot(uint32_t *a, uint32_t *n);
int mprime(uint32_t *n);
int mprimef(uint32_t *n, uint32_t *q, int k);
// ../eigenmath/src/brasket_fix.c :
void brasket_fix(char *target, int len);
// ../eigenmath/src/ceiling.c :
void eval_ceiling(void);
void ceiling_nib(void);
// ../eigenmath/src/circexp.c :
void eval_circexp(void);
void circexp(void);
void circexp_subst(void);
void circexp_subst_nib(void);
void eval_exptan(void);
void exptan(void);
void eval_expcosh(void);
void expcosh(void);
void eval_expsinh(void);
void expsinh(void);
void eval_exptanh(void);
void exptanh(void);
// ../eigenmath/src/clock.c :
void eval_clock(void);
void clockfunc(void);
void clockfunc_nib(void);
// ../eigenmath/src/coeff.c :
void eval_coeff(void);
int coeff(void);
// ../eigenmath/src/cofactor.c :
void eval_cofactor(void);
// ../eigenmath/src/conj.c :
void eval_conj(void);
void conjfunc(void);
void conjfunc_subst(void);
void conjfunc_subst_nib(void);
// ../eigenmath/src/contract.c :
void eval_contract(void);
void eval_contract_nib(void);
void contract(void);
void contract_nib(void);
// ../eigenmath/src/core.c :
struct atom * alloc(void);
struct atom * alloc_vector(int nrow);
struct atom * alloc_matrix(int nrow, int ncol);
struct atom * alloc_tensor(int nelem);
void gc(void);
void untag(struct atom *p);
void alloc_block(void);
void append(void);
void cons(void);
int find(struct atom *p, struct atom *q);
void list(int n);
int length(struct atom *p);
int complexity(struct atom *p);
int lessp(struct atom *p1, struct atom *p2);
void sort(int n);
int sort_func(const void *p1, const void *p2);
int cmp_expr(struct atom *p1, struct atom *p2);
int sign(int n);
int iszero(struct atom *p);
int isplusone(struct atom *p);
int isminusone(struct atom *p);
int isinteger(struct atom *p);
int isfraction(struct atom *p);
int isposint(struct atom *p);
int iseveninteger(struct atom *p);
int isradical(struct atom *p);
int isnegative(struct atom *p);
int isnegativeterm(struct atom *p);
int isnegativenumber(struct atom *p);
int iscomplexnumber(struct atom *p);
int isimaginarynumber(struct atom *p);
int isimaginaryunit(struct atom *p);
int isoneoversqrttwo(struct atom *p);
int isminusoneoversqrttwo(struct atom *p);
int isdoublez(struct atom *p);
int ispoly(struct atom *p, struct atom *x);
int ispoly_expr(struct atom *p, struct atom *x);
int ispoly_term(struct atom *p, struct atom *x);
int ispoly_factor(struct atom *p, struct atom *x);
int find_denominator(struct atom *p);
int count_denominators(struct atom *p);
int count_numerators(struct atom *p);
int isdenominator(struct atom *p);
int isnumerator(struct atom *p);
int isdoublesomewhere(struct atom *p);
int isdenormalpolar(struct atom *p);
int isdenormalpolarterm(struct atom *p);
int isdenormalclock(struct atom *p);
int issquarematrix(struct atom *p);
// ../eigenmath/src/cos.c :
void eval_cos(void);
void cosfunc(void);
void cosfunc_nib(void);
void cosfunc_sum(void);
// ../eigenmath/src/cosh.c :
void eval_cosh(void);
void coshfunc(void);
void coshfunc_nib(void);
// ../eigenmath/src/defint.c :
void eval_defint(void);
void eval_defint_nib(void);
// ../eigenmath/src/degree.c :
void eval_degree(void);
void degree(void);
void degree_nib(struct atom *p);
// ../eigenmath/src/denominator.c :
void eval_denominator(void);
void denominator(void);
void denominator_nib(void);
// ../eigenmath/src/derivative.c :
void eval_derivative(void);
void eval_derivative_nib(void);
void derivative(void);
void d_scalar_scalar(void);
void dsum(void);
void dproduct(void);
void dpower(void);
void dlog(void);
void dd(void);
void dfunction(void);
void dsin(void);
void dcos(void);
void dtan(void);
void darcsin(void);
void darccos(void);
void darctan(void);
void dsinh(void);
void dcosh(void);
void dtanh(void);
void darcsinh(void);
void darccosh(void);
void darctanh(void);
void dabs(void);
void derf(void);
void derfc(void);
void dbesselj0(void);
void dbesseljn(void);
void dbessely0(void);
void dbesselyn(void);
void derivative_of_integral(void);
// ../eigenmath/src/det.c :
void eval_det(void);
void det(void);
void det_nib(void);
// ../eigenmath/src/eigen.c :
void eval_eigen(void);
void eval_eigenval(void);
void eval_eigenvec(void);
int eigen_check_arg(void);
void eigen(int op);
int step(void);
void step2(int p, int q);
// ../eigenmath/src/equal.c :
int equal(struct atom *p1, struct atom *p2);
// ../eigenmath/src/erf.c :
void eval_erf(void);
void serf(void);
void serf_nib(void);
// ../eigenmath/src/erfc.c :
void eval_erfc(void);
void serfc(void);
void serfc_nib(void);
// ../eigenmath/src/eval.c :
void eval(void);
void eval_nib(void);
void eval_user_symbol(void);
void eval_binding(void);
void eval_clear(void);
void eval_do(void);
void eval_eval(void);
void eval_nil(void);
void eval_number(void);
void eval_quote(void);
void eval_sqrt(void);
void eval_stop(void);
void eval_subst(void);
void expand_expr(void);
// ../eigenmath/src/exp.c :
void eval_exp(void);
void expfunc(void);
// ../eigenmath/src/expand.c :
void eval_expand(void);
void expand(void);
void expand_tensor(void);
void remove_negative_exponents(void);
void expand_get_C(void);
void expand_get_CF(void);
void trivial_divide(void);
void expand_get_B(void);
void expand_get_A(void);
void expand_get_AF(void);
// ../eigenmath/src/expcos.c :
void eval_expcos(void);
void expcos(void);
// ../eigenmath/src/expsin.c :
void eval_expsin(void);
void expsin(void);
// ../eigenmath/src/factor.c :
void eval_factor(void);
void factor_again(void);
void factor_term(void);
void factor_rational(void);
void factor_small_number(void);
void factor_factor(void);
void factor_factor_nib(void);
void factor_bignum(uint32_t *a);
// ../eigenmath/src/factorial.c :
void eval_factorial(void);
void factorial(void);
void factorial_nib(void);
// ../eigenmath/src/factorpoly.c :
void factorpoly(void);
void factorpoly_nib(void);
void rationalize_coefficients(int h);
int get_factor(void);
void factor_divpoly(void);
void evalpoly(void);
void divisors_onstack(void);
void gen(int h, int k);
void factor_add(void);
// ../eigenmath/src/factors.c :
int factors(struct atom *p);
void push_term_factors(struct atom *p);
// ../eigenmath/src/filter.c :
void eval_filter(void);
void filter(void);
void filter_main(void);
void filter_sum(void);
void filter_tensor(void);
// ../eigenmath/src/float.c :
void eval_float(void);
void floatfunc(void);
void floatfunc_subst(void);
void floatfunc_subst_nib(void);
// ../eigenmath/src/floor.c :
void eval_floor(void);
void floorfunc(void);
void floorfunc_nib(void);
// ../eigenmath/src/fmt.c :
void fmt(void);
void fmt_args(struct atom *p);
void fmt_base(struct atom *p);
void fmt_denominators(struct atom *p);
void fmt_double(struct atom *p);
void fmt_exponent(struct atom *p);
void fmt_expr(struct atom *p);
void fmt_expr_nib(struct atom *p);
void fmt_factor(struct atom *p);
void fmt_frac(struct atom *p);
void fmt_function(struct atom *p);
void fmt_indices(struct atom *p);
void fmt_infix_operator(int c);
void fmt_list(struct atom *p);
void fmt_matrix(struct atom *p, int d, int k);
void fmt_numerators(struct atom *p);
void fmt_numeric_exponent(struct atom *p);
void fmt_power(struct atom *p);
void fmt_rational(struct atom *p);
void fmt_reciprocal(struct atom *p);
void fmt_roman_char(int c);
void fmt_roman_string(char *s);
void fmt_space(void);
void fmt_string(struct atom *p);
void fmt_subexpr(struct atom *p);
void fmt_symbol(struct atom *p);
int fmt_symbol_fragment(char *s, int k);
void fmt_table(int x, int y, struct atom *p);
void fmt_tensor(struct atom *p);
void fmt_term(struct atom *p);
void fmt_term_nib(struct atom *p);
void fmt_update_fraction(void);
void fmt_update_list(int t);
void fmt_update_subexpr(void);
void fmt_update_subscript(void);
void fmt_update_superscript(void);
void fmt_update_table(int n, int m);
void fmt_vector(struct atom *p);
void fmt_draw(int x, int y, struct atom *p);
void fmt_draw_char(int x, int y, int c);
void fmt_draw_delims(int x, int y, int h, int d, int w);
void fmt_draw_ldelim(int x, int y, int h, int d, int w);
void fmt_draw_rdelim(int x, int y, int h, int d, int w);
void fmt_draw_table(int x, int y, struct atom *p);
// ../eigenmath/src/for.c :
void eval_for(void);
// ../eigenmath/src/gcd.c :
void eval_gcd(void);
void gcd(void);
void gcd_main(void);
void gcd_expr_expr(void);
void gcd_expr(struct atom *p);
void gcd_term_term(void);
void gcd_term_factor(void);
void gcd_factor_term(void);
void gcd_numbers(void);
// ../eigenmath/src/globals.c :
// ../eigenmath/src/hadamard.c :
void eval_hadamard(void);
void hadamard(void);
void hadamard_nib(void);
// ../eigenmath/src/imag.c :
void eval_imag(void);
void imag(void);
void imag_nib(void);
// ../eigenmath/src/index.c :
void eval_index(void);
void indexfunc(int h);
// ../eigenmath/src/infixform.c :
void eval_infixform(void);
void print_infixform(struct atom *p);
void infixform_subexpr(struct atom *p);
void infixform_expr(struct atom *p);
void infixform_expr_nib(struct atom *p);
void infixform_term(struct atom *p);
void infixform_term_nib(struct atom *p);
void infixform_numerators(struct atom *p);
void infixform_denominators(struct atom *p);
void infixform_factor(struct atom *p);
void infixform_power(struct atom *p);
void infixform_reciprocal(struct atom *p);
void infixform_factorial(struct atom *p);
void infixform_index(struct atom *p);
void infixform_arglist(struct atom *p);
void infixform_rational(struct atom *p);
void infixform_double(struct atom *p);
void infixform_base(struct atom *p);
void infixform_numeric_token(struct atom *p);
void infixform_numeric_exponent(struct atom *p);
void infixform_tensor(struct atom *p);
void infixform_tensor_nib(struct atom *p, int d, int k);
// ../eigenmath/src/inner.c :
void eval_inner(void);
void inner(void);
void inner_nib(void);
// ../eigenmath/src/integral.c :
void eval_integral(void);
void eval_integral_nib(void);
void integral(void);
void integral_nib(void);
void integral_of_form(void);
void integral_lookup(int h);
int integral_classify(struct atom *p);
int find_integral(int h, char **s);
int find_integral_nib(int h);
void decomp(void);
void decomp_nib(void);
void decomp_sum(void);
void decomp_product(void);
void collect_coeffs(void);
void collect_coeffs_nib(void);
int collect_coeffs_sort_func(const void *q1, const void *q2);
void partition_integrand(void);
// ../eigenmath/src/inv.c :
void eval_inv(void);
void inv(void);
void inv_nib(void);
// ../eigenmath/src/isprime.c :
void eval_isprime(void);
// ../eigenmath/src/kronecker.c :
void eval_kronecker(void);
void kronecker(void);
void kronecker_nib(void);
// ../eigenmath/src/latex.c :
void eval_latex(void);
void latex(void);
void latex_nib(void);
void latex_expr(struct atom *p);
void latex_term(struct atom *p);
void latex_numerators(struct atom *p);
void latex_denominators(struct atom *p);
void latex_factor(struct atom *p);
void latex_number(struct atom *p);
void latex_rational(struct atom *p);
void latex_double(struct atom *p);
void latex_power(struct atom *p);
void latex_base(struct atom *p);
void latex_exponent(struct atom *p);
void latex_imaginary(struct atom *p);
void latex_function(struct atom *p);
void latex_arglist(struct atom *p);
void latex_subexpr(struct atom *p);
void latex_symbol(struct atom *p);
int latex_symbol_scan(char *s);
void latex_symbol_shipout(char *s, int n);
void latex_tensor(struct atom *p);
void latex_tensor_matrix(struct tensor *t, int d, int *k);
void latex_string(struct atom *p);
// ../eigenmath/src/lcm.c :
void eval_lcm(void);
void lcm(void);
void lcm_nib(void);
// ../eigenmath/src/leading.c :
void eval_leading(void);
void leading(void);
// ../eigenmath/src/log.c :
void eval_log(void);
void logfunc(void);
void logfunc_nib(void);
// ../eigenmath/src/mag.c :
void eval_mag(void);
void mag(void);
void mag_nib(void);
void mag1(void);
void mag1_nib(void);
// ../eigenmath/src/main.c :
int main(int argc, char *argv[]);
void run_stdin(void);
void prompt(void);
void echo(void);
void run_infile(void);
void printbuf(char *s, int color);
void display(void);
void begin_document(void);
void end_document(void);
void begin_latex(void);
void end_latex(void);
void begin_mathml(void);
void end_mathml(void);
void begin_mathjax(void);
void end_mathjax(void);
void eval_draw(void);
void eval_exit(void);
// ../eigenmath/src/mathjax.c :
void eval_mathjax(void);
void mathjax(void);
void mathjax_nib(void);
// ../eigenmath/src/mathml.c :
void eval_mathml(void);
void mathml(void);
void mathml_nib(void);
void mml_expr(struct atom *p);
void mml_term(struct atom *p);
void mml_numerators(struct atom *p);
void mml_denominators(struct atom *p);
void mml_factor(struct atom *p);
void mml_number(struct atom *p);
void mml_rational(struct atom *p);
void mml_double(struct atom *p);
void mml_power(struct atom *p);
void mml_base(struct atom *p);
void mml_exponent(struct atom *p);
void mml_imaginary(struct atom *p);
void mml_function(struct atom *p);
void mml_arglist(struct atom *p);
void mml_subexpr(struct atom *p);
void mml_symbol(struct atom *p);
int mml_symbol_scan(char *s);
void mml_symbol_shipout(char *s, int n);
void mml_tensor(struct atom *p);
void mml_matrix(struct tensor *t, int d, int *k);
void mml_string(struct atom *p, int mathmode);
void mml_mi(char *s);
void mml_mn(char *s);
void mml_mo(char *s);
// ../eigenmath/src/minor.c :
void eval_minor(void);
void eval_minormatrix(void);
void minormatrix(int row, int col);
void minormatrix_nib(int row, int col);
// ../eigenmath/src/mod.c :
void eval_mod(void);
void modfunc(void);
void modfunc_nib(void);
void modfunc_rationals(void);
// ../eigenmath/src/multiply.c :
void eval_multiply(void);
void multiply(void);
void multiply_factors(int n);
void multiply_factors_nib(int n);
void flatten_factors(int h);
void multiply_tensor_factors(int h);
void multiply_scalar_factors(int h);
void combine_numerical_factors(int h);
void combine_factors(int h);
void sort_factors_provisional(int n);
int sort_factors_provisional_func(const void *q1, const void *q2);
int cmp_factors_provisional(struct atom *p1, struct atom *p2);
int combine_adjacent_factors(struct atom **s);
void factor_factors_maybe(int h);
void normalize_power_factors(int h);
void expand_sum_factors(int h);
void sort_factors(int n);
int sort_factors_func(const void *q1, const void *q2);
int cmp_factors(struct atom *p1, struct atom *p2);
int order_factor(struct atom *p);
void multiply_numbers(void);
void multiply_rationals(void);
void reduce_radical_factors(int h);
void multiply_expand(void);
void multiply_noexpand(void);
void multiply_factors_noexpand(int n);
void negate(void);
void negate_noexpand(void);
void reciprocate(void);
void divide(void);
// ../eigenmath/src/noexpand.c :
void eval_noexpand(void);
// ../eigenmath/src/nroots.c :
void eval_nroots(void);
void monic(int n);
void findroot(int n);
void compute_fa(int n);
void nroots_divpoly(int n);
// ../eigenmath/src/numerator.c :
void eval_numerator(void);
void numerator(void);
void numerator_nib(void);
// ../eigenmath/src/outer.c :
void eval_outer(void);
void outer(void);
void outer_nib(void);
// ../eigenmath/src/polar.c :
void eval_polar(void);
void polar(void);
void polar_nib(void);
// ../eigenmath/src/pollard.c :
void factor_number(void);
void factor_a(void);
void try_kth_prime(int k);
int factor_b(void);
void push_factor(uint32_t *d, int count);
// ../eigenmath/src/power.c :
void eval_power(void);
void power(void);
void power_nib(void);
void power_natural_number(void);
void normalize_polar(void);
void normalize_polar_term(void);
void normalize_polar_term_rational(void);
void normalize_polar_term_double(void);
void power_sum(void);
void power_minusone(void);
void normalize_clock_rational(void);
void normalize_clock_double(void);
void power_complex_number(void);
void power_complex_plus(int n);
void power_complex_minus(int n);
void power_complex_double(void);
void power_complex_rational(void);
void power_numbers(void);
void power_rationals(void);
void power_rationals_nib(void);
void sqrtfunc(void);
void power_tensor(void);
// ../eigenmath/src/prefixform.c :
void eval_prefixform(void);
void print_prefixform(struct atom *p);
void prefixform(struct atom *p);
// ../eigenmath/src/prime.c :
void eval_prime(void);
void prime(void);
// ../eigenmath/src/primetab.c :
// ../eigenmath/src/print.c :
void eval_print(void);
void print_result(void);
void print_result_nib(void);
void prep_symbol_equals(void);
void print_str(char *s);
void print_char(int c);
// ../eigenmath/src/product.c :
void eval_product(void);
// ../eigenmath/src/quotient.c :
void eval_quotient(void);
void divpoly(void);
// ../eigenmath/src/rationalize.c :
void eval_rationalize(void);
void rationalize(void);
void rationalize_nib(void);
// ../eigenmath/src/real.c :
void eval_real(void);
void real(void);
void real_nib(void);
// ../eigenmath/src/rect.c :
void eval_rect(void);
void rect(void);
void rect_nib(void);
// ../eigenmath/src/roots.c :
void eval_roots(void);
void roots(void);
void roots2(void);
void roots3(void);
void mini_solve(void);
// ../eigenmath/src/rotate.c :
void eval_rotate(void);
void rotate_h(uint32_t c, int n);
void rotate_p(uint32_t c, int n);
void rotate_w(uint32_t c, int m, int n);
void rotate_x(uint32_t c, int n);
void rotate_y(uint32_t c, int n);
void rotate_z(uint32_t c, int n);
void rotate_q(int n);
void rotate_v(int n);
// ../eigenmath/src/run.c :
void run(char *s);
void init(void);
void prep(void);
char * scan_input(char *s);
void eval_and_print_result(void);
void eval_run(void);
void run_file(char *filename);
void trace_input(void);
void print_input_line(void);
void print_scan_line(char *s);
void eval_status(void);
void run_init_script(void);
void stop(char *s);
void kaput(char *s);
void malloc_kaput(void);
// ../eigenmath/src/scan.c :
char * scan(char *s);
char * scan1(char *s);
char * scan_nib(char *s);
void scan_stmt(void);
void scan_comparison(void);
void scan_expression(void);
int another_factor_pending(void);
void scan_term(void);
void scan_power(void);
void scan_factor(void);
void scan_symbol(void);
void scan_string(void);
void scan_function_call(void);
void scan_subexpr(void);
void get_token_skip_newlines(void);
void get_token(void);
void get_token_nib(void);
void update_token_buf(char *a, char *b);
void scan_error(char *errmsg);
void build_tensor(int h);
void static_negate(void);
void static_negate_nib(void);
void static_reciprocate(void);
void static_reciprocate_nib(void);
// ../eigenmath/src/setq.c :
void eval_setq(void);
void setq_indexed(void);
void set_component(int h);
void set_component_nib(int h);
void setq_usrfunc(void);
void convert_body(void);
// ../eigenmath/src/sgn.c :
void eval_sgn(void);
void sgn(void);
// ../eigenmath/src/simplify.c :
void eval_simplify(void);
void simplify(void);
void simplify_nib(void);
void simplify_pass1(void);
void simplify_pass2(void);
// ../eigenmath/src/sin.c :
void eval_sin(void);
void sinfunc(void);
void sinfunc_nib(void);
void sinfunc_sum(void);
// ../eigenmath/src/sinh.c :
void eval_sinh(void);
void sinhfunc(void);
void sinhfunc_nib(void);
// ../eigenmath/src/stack.c :
void push(struct atom *p);
struct atom * pop(void);
void save(void);
void restore(void);
void save_symbol(struct atom *p);
void restore_symbol(struct atom *p);
void swap(void);
void push_string(char *s);
// ../eigenmath/src/subst.c :
void subst(void);
void subst_nib(void);
// ../eigenmath/src/sum.c :
void eval_sum(void);
// ../eigenmath/src/symbol.c :
struct atom * lookup(char *s);
char * printname(struct atom *p);
void set_symbol(struct atom *p, struct atom *b, struct atom *u);
void undo(void);
struct atom * get_binding(struct atom *p);
struct atom * get_usrfunc(struct atom *p);
struct se;
void init_symbol_table(void);
void clear_symbols(void);
// ../eigenmath/src/tan.c :
void eval_tan(void);
void tanfunc(void);
void tanfunc_nib(void);
void tanfunc_sum(void);
// ../eigenmath/src/tanh.c :
void eval_tanh(void);
void tanhfunc(void);
void tanhfunc_nib(void);
// ../eigenmath/src/tensor.c :
void eval_tensor(void);
void promote_tensor(void);
void promote_tensor_nib(void);
int compatible_dimensions(struct atom *p, struct atom *q);
void d_tensor_tensor(void);
void d_scalar_tensor(void);
void d_tensor_scalar(void);
int compare_tensors(struct atom *p1, struct atom *p2);
void copy_tensor(void);
void eval_dim(void);
void eval_rank(void);
void eval_unit(void);
void eval_unit_nib(void);
void eval_zero(void);
void eval_zero_nib(void);
// ../eigenmath/src/test.c :
void eval_test(void);
void eval_test_nib(void);
void eval_check(void);
void eval_testeq(void);
int cross_expr(struct atom *p);
int cross_term(struct atom *p);
int cross_factor(struct atom *p);
void cancel_factor(void);
void eval_testge(void);
void eval_testgt(void);
void eval_testle(void);
void eval_testlt(void);
void eval_not(void);
void eval_and(void);
void eval_and_nib(void);
void eval_or(void);
void eval_or_nib(void);
int cmp_args(void);
void evalp(void);
// ../eigenmath/src/transpose.c :
void eval_transpose(void);
void eval_transpose_nib(void);
void transpose(void);
void transpose_nib(void);
// ../eigenmath/src/userfunc.c :
void eval_user_function(void);
void eval_user_function_nib(void);
