#include <stdio.h>

void custom_swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int first, second = 0;
	char* number;

	printf("Please enter first number: ");
	fgets(number, 257, stdin);
	sscanf(number, "%d", &first);

	printf("Please enter second number: ");
	fgets(number, 257, stdin);
	sscanf(number, "%d", &second);

	custom_swap(&first, &second);
	printf("Before swap | a -> %d, b -> %d. After swap | a -> %d, b -> %d.", second, first, first, second);
}
