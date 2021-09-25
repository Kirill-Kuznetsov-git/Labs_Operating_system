#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {	char str[100];	int res = 0;	while (1) {		fgets(str, 100, stdin);		system(str);	}}