#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXCHAR 1000

void print_matrix(int** matrix, int numberOfLines, int numberColumns){
    for(int row=0; row<numberOfLines; row++){
        for(int columns=0; columns<numberColumns; columns++){
         printf("%d ", matrix[row][columns]);
        }
    printf("\n");
    }
}

int string_to_int(char* string){
    int res = 0;
    int m = 1;
    for(int i = 0; i < strlen(string); i++){
        m = 1;
        for (int j = 0; j < strlen(string) - (i + 1); j++){
            m = m * 10;
        }
        res += (string[i] - '0') * m;
    }
    return res;
}


int main() {
    FILE* fp;
    int** matrix;
    int matrix_size = 0;
    char row[MAXCHAR];
    char* tmp_row;

    int tmp_a;
    int tmp_b;
    int tmp_a_1;
    int tmp_b_1;

    char* a;
    char* b;

    fp = fopen("new_input.csv", "r");

    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);

        a = strtok(row, ",");
        b = strtok(NULL, ",");

        if (b != NULL && a != NULL){
            b[strlen(b) - 1] = '\0';
            matrix[matrix_size++] = malloc(2 * sizeof(int));
            matrix[matrix_size - 1][0] = string_to_int(a);
            matrix[matrix_size - 1][1] = string_to_int(b);
            for (int i = 0;i < matrix_size; i++){
                if (matrix[i][0] > string_to_int(a) || (matrix[i][0] == string_to_int(a) && matrix[i][1] < string_to_int(b))){
                    tmp_a = matrix[i][0];
                    tmp_b = matrix[i][1];
                    matrix[i][0] = string_to_int(a);
                    matrix[i][1] = string_to_int(b);
                    i++;
                    while (i < matrix_size){
                        tmp_a_1 = matrix[i][0];
                        tmp_b_1 = matrix[i][1];
                        matrix[i][0] = tmp_a;
                        matrix[i][1] = tmp_b;
                        tmp_a = tmp_a_1;
                        tmp_b = tmp_b_1;
                        i++;
                    }

                }
            }
        }
    }
    print_matrix(matrix, matrix_size, 2);
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    int time = 0;
    double turn_sum = 0;
    double wt_sum = 0;
    for (int i = 0; i < matrix_size; i++){
        if (i == 0){
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, matrix[i][0], matrix[i][1], matrix[i][0] + matrix[i][1], matrix[i][1], 0);
            time = matrix[i][0] + matrix[i][1];
            turn_sum += matrix[i][1];
        }
        else{
            int waiting = time - matrix[i][0] <= 0 ? 0:time - matrix[i][0];
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, matrix[i][0], matrix[i][1], matrix[i][0] + matrix[i][1] + waiting, matrix[i][1] + waiting, waiting);
            time = matrix[i][0] + matrix[i][1] + waiting;
            turn_sum += matrix[i][1] + waiting;
            wt_sum += waiting;
        }
    }
    printf("Average Turnaround Time = %f\n", (turn_sum / matrix_size));
    printf("Average WT = %f\n", (wt_sum / matrix_size));
    return 0;

}
