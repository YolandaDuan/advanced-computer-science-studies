CC = gcc
CFLAGS=-Wall


io_handling : io_handling.o joystick.o led_matrix.o
	$(CC) $(CFLAGS) -lpthread -o io_handling io_handling.o joystick.o led_matrix.o

io_handling.o : io_handling.c
	$(CC) $(CFLAGS) -c io_handling.c

joystick.o : joystick.c
	$(CC) $(CFLAGS) -c joystick.c

led_matrix.o : led_matrix.c
	$(CC) $(CFLAGS) -c led_matrix.c

clean :
	rm -f io_handling.o joystick.o led_matrix.o

