prototype-gen : prototype-gen.o

prototype-gen.exe : CC = x86_64-w64-mingw32-gcc
prototype-gen.exe : CFLAGS = -W
prototype-gen.exe : prototype-gen.o

clean : *.o
	rm *.o