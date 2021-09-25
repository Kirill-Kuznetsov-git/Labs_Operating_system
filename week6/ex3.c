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
    int tmp_b1;
    int tmp_a_1;
    int tmp_b_1;
    int tmp_b1_1;


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
            matrix[matrix_size++] = malloc(3 * sizeof(int));
            matrix[matrix_size - 1][0] = string_to_int(a);
            matrix[matrix_size - 1][1] = string_to_int(b);
            matrix[matrix_size - 1][2] = string_to_int(b);
            for (int i = 0;i < matrix_size; i++){
                if (matrix[i][0] > string_to_int(a) || (matrix[i][0] == string_to_int(a) && matrix[i][1] < string_to_int(b))){
                    tmp_a = matrix[i][0];
                    tmp_b = matrix[i][1];
                    tmp_b1 = matrix[i][2];
                    matrix[i][0] = string_to_int(a);
                    matrix[i][1] = string_to_int(b);
                    matrix[i][2] = string_to_int(b);
                    i++;
                    while (i < matrix_size){
                        tmp_a_1 = matrix[i][0];
                        tmp_b_1 = matrix[i][1];
                        tmp_b1_1 = matrix[i][2];
                        matrix[i][0] = tmp_a;
                        matrix[i][1] = tmp_b;
                        matrix[i][2] = tmp_b1;
                        tmp_a = tmp_a_1;
                        tmp_b = tmp_b_1;
                        tmp_b1 = tmp_b1_1;
                        i++;
                    }

                }
            }
        }
    }
    int number_waiting_processes = matrix_size;
    int time = matrix[0][0];
    int quantum = 0;
    int all_completed = 1;
    int flag = 0;
    int now_time = matrix[0][0];
    scanf("%d", &quantum);

    while (number_waiting_processes > 0){
        flag = 0;
        for (int i = 0; i < matrix_size; i++){
            if (matrix[i][2] > matrix[i][1]){
                continue;
            }
            if (matrix[i][0] == now_time){
                flag = 1;
                if (matrix[i][2] - quantum <= 0){
                    number_waiting_processes -= 1;
                    time += matrix[i][2];
                    if (i == 0){
                        matrix[i][2] = time;
                    }
                    else{
                        matrix[i][2] = time + 1;
                    }

                }
                else{
                    time += quantum;
                    matrix[i][2] = matrix[i][2] - quantum;
                }
            }
        }
        if (!flag){
            for (int i = 0; i < matrix_size; i++){
                if (matrix[i][0] > now_time){
                    now_time = matrix[i][0];
                    break;
                }
            }
        }
    }

    double turn_sum = 0.0;
    double wt_sum = 0;
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 0; i < matrix_size; i++){
        turn_sum += matrix[i][2] - matrix[i][0];
        wt_sum += matrix[i][2] - matrix[i][0] - matrix[i][1];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][2] - matrix[i][0], matrix[i][2] - matrix[i][0] - matrix[i][1]);
    }
    printf("Average Turnaround Time = %f\n", (turn_sum / matrix_size));
    printf("Average WT = %f\n", (wt_sum / matrix_size));
    return 0;

}
// Add index to each process
// If process must be split then add to matrix new array with the same 'b' and process's index but another 'a'
