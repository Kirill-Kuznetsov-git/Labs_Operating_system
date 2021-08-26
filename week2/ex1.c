#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("Integer = %d\nFloat = %f\nDouble = %f\nSizeof integer = %lu\nSizeof float = %lu\nSizeof double = %lu\n", a, b, c, sizeof(a), sizeof(b), sizeof(c));
	return 0;
}
