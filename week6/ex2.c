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

bool in_array(int* index, int size, int in){
    for (int i = 0;i < size; i ++){
        if (index[i] == in){ return true; }
    }
    return false;
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
                if (matrix[i][0] > string_to_int(a)){
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
    double turn_sum = 0.0;
    double wt_sum = 0;
    int shortest = 1000;
    int shortest_index = -1;
    int indexes[matrix_size];
    int indexes_size = 0;
    int time = matrix[0][0];

    while (indexes_size != matrix_size){
        for(int i = 0; i < matrix_size; i++){
            if (matrix[i][1] < shortest && !in_array(indexes, indexes_size, i)){
                shortest = matrix[i][1];
                shortest_index = i;
            }
            if (matrix[i][0] > time){ break; }
        }
        time = (time > matrix[shortest_index][0] ? time : matrix[shortest_index][0]) + matrix[shortest_index][1];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", indexes_size, matrix[shortest_index][0], matrix[shortest_index][1], time, time - matrix[shortest_index][0], time - matrix[shortest_index][0] - matrix[shortest_index][1]);
        indexes[indexes_size] = shortest_index;
        indexes_size++;
        shortest = 1000;
        turn_sum += time - matrix[shortest_index][0];
        wt_sum += time - matrix[shortest_index][0] - matrix[shortest_index][1];
    }

    printf("Average Turnaround Time = %f\n", (turn_sum / matrix_size));
    printf("Average WT = %f\n", (wt_sum / matrix_size));
    return 0;

}
