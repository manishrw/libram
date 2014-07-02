CC=gcc
CFLAGS=-Wall

all: libcodegeeta.a

libcodegeeta.a: codegeeta.o
	ar rcs libcodegeeta.a codegeeta.o

codegeeta.o: codegeeta.c
	$(CC) $(CFLAGS) -c -I. codegeeta.c -o codegeeta.o

test: test.c libcodegeeta.a
	$(CC) $(CFLAGS) -static -I. test.c -L. -lcodegeeta -o test

clean:
	rm -rf *.o *.a test
