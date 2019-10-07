#include <stdio.h>
#include <pthread.h>

void *function_to_run(void *arg) {
	int n = *(int *) arg;
	printf("I'm the new thread! I got %d passed to me.\n", n);
	return NULL;
}

int main() {
	pthread_t mythread;
	int n = 5;

	printf("Creating a new thread...\n");
	if (pthread_create(&mythread, NULL, function_to_run, &n)) {
		fprintf(stderr, "Error creating new thread.\n");
		return -1;
	}

	printf("Waiting for the new thread to terminate...\n");
	pthread_join(mythread, NULL);
	printf("New thread has terminated.\n");

	return 0;
}

