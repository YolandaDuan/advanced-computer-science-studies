#include <stdio.h>
#include "joystick.h"

int main() {

	struct js_event ev;
	open_joystick_device();

	while (1) {
		ev = read_joystick_input();
		if (ev.type == JOYSTICK_PRESS) {
			if (ev.direction == DIRECTION_NORTH) {
				printf("Pressed north!\n");
			} else if (ev.direction == DIRECTION_SOUTH) {
				printf("Pressed south!\n");
			} else if (ev.direction == DIRECTION_WEST) {
				printf("Pressed west!\n");
			} else if (ev.direction == DIRECTION_EAST) {
				printf("Pressed east!\n");
			} else if (ev.direction == DIRECTION_DOWN) {
				printf("Pressed down!\n");
			}
		} else if (ev.type == JOYSTICK_RELEASE) {
			if (ev.direction == DIRECTION_NORTH) {
				printf("Released north!\n");
			} else if (ev.direction == DIRECTION_SOUTH) {
				printf("Released south!\n");
			} else if (ev.direction == DIRECTION_WEST) {
				printf("Released west!\n");
			} else if (ev.direction == DIRECTION_EAST) {
				printf("Released east!\n");
			} else if (ev.direction == DIRECTION_DOWN) {
				printf("Released down!\n");
			}
		} else if (ev.type == JOYSTICK_HOLD) {
			if (ev.direction == DIRECTION_NORTH) {
				printf("Hold north!\n");
			} else if (ev.direction == DIRECTION_SOUTH) {
				printf("Hold south!\n");
			} else if (ev.direction == DIRECTION_WEST) {
				printf("Hold west!\n");
			} else if (ev.direction == DIRECTION_EAST) {
				printf("Hold east!\n");
			} else if (ev.direction == DIRECTION_DOWN) {
				printf("Hold down!\n");
			}
		}
	}

	close_joystick_device();
	return 0;
}

