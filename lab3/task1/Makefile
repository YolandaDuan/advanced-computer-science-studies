CC = gcc
CFLAGS=-Wall


program : program.o led_matrix.o
	$(CC) -o program program.o led_matrix.o

program.o : program.c
	$(CC) -c program.c

led_matrix.o : led_matrix.c
	$(CC) -c led_matrix.c

clean :
	rm program.o led_matrix.o

