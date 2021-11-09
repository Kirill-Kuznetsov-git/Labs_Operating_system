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

    while (fread(&input_event_var, sizeof(struct input_event), 1, f)) {
        if (input_event_var.type == EV_KEY) {
            if (input_event_var.value == 0) {
                printf("%s 0x%04x (%d) \n", "RELEASED", input_event_var.code, input_event_var.code);
            }
            else if (input_event_var.value == 1) {
                printf("%s 0x%04x (%d) \n", "PRESSED", input_event_var.code, input_event_var.code);
            }
        }
    }
    fclose(f);
}
