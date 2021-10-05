#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXCHAR 1000

int main(){
    int n;
    scanf("%d", &n);
    int *array = (int*)calloc(n, sizeof(int));
    printf("Array: ");
    for (int i = 0; i < n; i++){
        array[i] = i;
        printf("%d ", i);
    }
    printf("\n");
    free(array);
    return 0;
}