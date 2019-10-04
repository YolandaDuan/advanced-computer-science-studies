#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "led_matrix.h"

int col;
/*
* Do some pointless CPU - heavy computations . Takes about 1 second
* to complete on a single core of the ARM Cortex A53 processor of
* the Raspberry Pi 3 model B with default gcc 6.3.0 op tim iz at io ns .
*/
void pointless_calculation () {
int amount_of_pointlessness = 100000000;
int x = 0;
for ( int i = 0; i < amount_of_pointlessness ; i ++) {
x += i;
 }
}
void run_child(int n) {
for (col = 0;col<=8;col++) {
 open_led_matrix();
 pointless_calculation ();
 usleep (1000000) ;
 set_led(n, col, RGB565_RED);
}
clear_leds();
close_led_matrix();
}

int main() {
    int n,num_children,j;
    open_led_matrix();
    for(num_children = 0;num_children<=8;num_children++){
	for(n = 0;n<num_children;n++)
	{
		int pid=fork();
		if(pid==0){
		nice(n);
		run_child(n);
		exit(0);
		}
	}
	for(j=0;j<=num_children;j++)
	{
	wait(NULL);
	}
	usleep(1000000);
	clear_leds();

}
   close_led_matrix();
   // run_child(n);
   return 0;
}
