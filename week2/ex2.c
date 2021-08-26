#include <stdio.h>
#include <string.h>

int main()
{
	char s[80], temp;
	int i, j = 0;
	printf("Enter a string: ");
	fgets(s, 80, stdin);
	i = 0;
	j = strlen(s) - 1;
	while (i < j){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	printf("Here is your reverse string: %s\n", s);
	return 0;
}

