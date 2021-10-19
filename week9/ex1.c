#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define NUMBER_BITS 16

int main() {
    int number_pages;
    double number_hits = 0;
    double number_ref = 0;
    FILE* file = fopen("Lab 09 input.txt", "r");
    scanf("%d", &number_pages);

    uint16_t* r_clock = malloc(number_pages * sizeof(uint16_t));
    int* id_pages = calloc(number_pages, sizeof(int));

    int current_id_page = 0;
    bool flag = false;

    int applicant_i = 0;
    int applicant_id;
    uint16_t applicant_r_clock = UINT16_MAX;
    printf("Print the number of pages\n");
    while(fscanf(file, "%d", &current_id_page) != EOF){
        number_ref++;
        flag = false;
        applicant_i = 0;
        applicant_id = -1;
        applicant_r_clock = UINT16_MAX;

        for (int i = 0; i < number_pages;i++){
            printf("i = %d id = %d %d\n", i, id_pages[i], r_clock[i]);
        }
        printf("current page number %d\n\n", current_id_page);

        for (int i = 0;i < number_pages;i++){
            if (id_pages[i] != current_id_page && id_pages[i] != 0){
                r_clock[i] >>= 1;
            }
            if (id_pages[i] == current_id_page){
                printf("1");
                flag = true;
                number_hits++;
                r_clock[i] |= 1 << (NUMBER_BITS - 1);
            }
        }
        if (flag == false){
            for (int i = 0;i < number_pages;i++){
                if (applicant_r_clock >= r_clock[i] && ((applicant_id != 0) || (applicant_id == 0 && id_pages[i] == 0))){
                    applicant_r_clock = r_clock[i];
                    applicant_id = id_pages[i];
                    applicant_i = i;
                }
            }
            id_pages[applicant_i] = current_id_page;
            r_clock[applicant_i] = pow(2, 15);
        }

    }
    printf("Hit = %f Miss = %f Ratio = %f\n", number_hits, number_ref - number_hits, number_hits / (number_ref - number_hits));

    return 0;
}
