prototype-gen : prototype-gen.o

prototype-gen-win : CC = x86_64-w64-mingw32-gcc
prototype-gen-win : CFLAGS = -w
prototype-gen-win : LDFLAGS = -lshlwapi
prototype-gen-win : prototype-gen.o
	$(CC) $(CFLAGS) prototype-gen.o $(LDFLAGS) -o prototype-gen.exe

clean : *.o
	rm *.o