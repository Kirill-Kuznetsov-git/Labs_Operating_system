#include <errno.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    struct input_event input_event_var;
    FILE *f = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = 0;
    }

    printf("PE - I passed the Exam!\"\n");
    printf("CAP - Get some cappuccino!\"\n");
    printf("WGA - Want to get A!\"\n");

    while (fread(&input_event_var, sizeof(struct input_event), 1, f)) {
        if (input_event_var.type == EV_KEY) {
            if (input_event_var.value == 0) {
                array[input_event_var.code] = 0;
            }
            else if (input_event_var.value == 1) {
            	printf("%d\n", input_event_var.code);
                array[input_event_var.code] = 1;
                if(array[25] && array[18]) {
                    printf("I passed the Exam!\n");
                }
                else if(array[46] && array[30] && array[25]) {
                    printf("Get some cappuccino!\n");
                }
                else if(array[17] && array[34] && array[30]) {
                    printf("Want to get A!\n");
                }
            }
        }
    }
    fclose(f);
}
