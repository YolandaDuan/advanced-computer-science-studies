CC = gcc
CFLAGS=-Wall


joystick_example : joystick_example.o joystick.o
	$(CC) $(CFLAGS) -o joystick_example joystick_example.o joystick.o

joystick_example.o : joystick_example.c
	$(CC) $(CFLAGS) -c joystick_example.c

joystick.o : joystick.c
	$(CC) $(CFLAGS) -c joystick.c

clean :
	rm -f joystick_example.o joystick.o

