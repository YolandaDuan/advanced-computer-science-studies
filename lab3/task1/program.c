#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "led_matrix.h"
int main()
{
open_led_matrix();
int pid = fork();
if (pid == 0)
{
printf("I'm the child! Lighting LED at (1,2)...\n");
set_led(1,2, RGB565_GREEN);
}
// parent process because return value non-zero.

else
{
printf("I'm the parent! Lighting LED at (3,2)...\n");
set_led(2, 1, RGB565_RED);
wait(NULL);
usleep(2000000);
clear_leds();
close_led_matrix();
}
return 0;
}
