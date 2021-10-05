#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXCHAR 1000

void *realloc(void *ptr, size_t size){
    void *array_new = malloc(size * sizeof(void));
    if (ptr != NULL){
        memcpy(array_new, ptr, size);
    }
    free(ptr);
    return array_new;
}


int main(){
    int *ptr = malloc(10 * sizeof(void));;
    ptr = realloc(ptr, 13);
    for (int i = 0;i < 13; i++){
        printf("%d ", ptr[i]);
    }
    return 0;
}