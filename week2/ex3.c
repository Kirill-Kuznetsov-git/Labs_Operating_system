#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	int add_number = 0;
	sscanf(argv[1], "%d", &number);
	add_number = number - 1;
	for (int i = 0;i < number;i++){
		for (int j = 0;j < add_number;j++){
			printf(" ");
		}
		for (int j = 0;j < 1 + i * 2;j++){
			printf("*");
		}
		for (int j = 0;j < add_number;j++){
			printf(" ");
		}
		printf("\n");
		add_number = add_number - 1;
	}
}
