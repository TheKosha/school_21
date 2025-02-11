GCC = gcc -Wall -Wextra -Werror
all: cipher logging_cipher

cipher: cipher.o logger.o
	$(GCC) -c cipher.c -o cipher.o
	$(GCC) -c logger.c -o logger.o
	$(GCC) cipher.o logger.o -o ../build/cipher
	rm cipher.o logger.o

logging_cipher: cipher.o logger.o
	$(GCC) -c cipher.c -o cipher.o
	$(GCC) -c logger.c -o logger.o
	$(GCC) cipher.o logger.o -o ../build/logging_cipher
	rm cipher.o logger.o

clean:
	rm ../build/cipher ../build/logging_cipher
	rm -f *.o

rebild:
	make clean
	make all