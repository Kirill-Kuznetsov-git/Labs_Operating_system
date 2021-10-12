#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    for (int i = 0;i < 100; i++){
        int* array = malloc(1000 * 1024 * 256 * sizeof(int));
        memset(array, 0, 10 * 1024 * 256 * sizeof(int));
        sleep(1);
    }
}