#include <stdio.h>
#include <unistd.h>

int main() {
	int n = 42;
	int id = fork();
	if (id != 0) {
		printf("Hello from parent [%d - %d]\n", id, n);
	}
	else {
		printf("Hello from child[%d - %d]\n", id, n);
	}	return 0;}