#include <stdio.h>

#define NUMBER_ROWS 5
#define NUMBER_COLOMNS 3

int main(){
    int e[NUMBER_COLOMNS];
    int a[NUMBER_COLOMNS];
    int b;
    int need[NUMBER_COLOMNS] = {0, 0, 0};
    for (int i = 0; i < NUMBER_COLOMNS; i++){
        scanf("%d", &e[i]);
    }

        for (int i = 0; i < NUMBER_COLOMNS; i++){
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < NUMBER_ROWS; i++){
        for (int j = 0; j < NUMBER_COLOMNS; j++){
            scanf("%d", &b);
        }
    }

    for (int i = 0; i < NUMBER_ROWS; i++){
        for (int j = 0; j < NUMBER_COLOMNS; j++){
            scanf("%d", &b);
            need[j] += b;
        }
    }
    
    for (int i = 0; i < NUMBER_COLOMNS; i++){
        if (need[i] > e[i]){
            printf("Deadlock\n");
            return 0;
        }
    }
    printf("Ended Successfully\n");
    return 0;
}