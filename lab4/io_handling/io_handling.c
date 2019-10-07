#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "joystick.h"
#include "led_matrix.h"


uint16_t snek_color = RGB565_CYAN;
int snek_len = 3;


void sleep_ms(int ms) {
	usleep(1000 * ms);
}

int main() {
	int snek_pos = 0;
	open_led_matrix();

	/* Move the snek. */
	while (1) {
		clear_leds();
		snek_pos = (snek_pos + 1) % NUM_LEDS;	
		for (int i = 0; i < snek_len; i++) {
			int led_num = (snek_pos + i) % NUM_LEDS;
			set_led_num(led_num, snek_color);
		}
		sleep_ms(100);
	}
	
	close_led_matrix();
}

