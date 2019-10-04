CC = gcc
CFLAGS=-Wall


program1 : program1.o led_matrix.o
	$(CC) -o program1 program1.o led_matrix.o

program1.o : program1.c
	$(CC) -c program1.c

led_matrix.o : led_matrix.c
	$(CC) -c led_matrix.c

clean :
	rm program1.o led_matrix.o

