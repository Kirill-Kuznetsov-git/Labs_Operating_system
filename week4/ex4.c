#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char cmd[100];
    char* argv[3];
    bool with_arg = false;
    argv[0] = (char*)malloc(100 * sizeof(char));
    argv[1] = (char*)malloc(100 * sizeof(char));
    argv[2] = NULL;

    while (1) {
        with_arg = false;
        fgets(cmd, 256, stdin);
        for (int i = 0; i < strlen(cmd); i++) {
            if (cmd[i] == ' ') {
                strncpy(argv[0], cmd, i);
                strncpy(argv[1], cmd + i + 1, strlen(cmd) - i - 2);
                strcpy(cmd, argv[0]);
                with_arg = true;
                break;
            }
        }
        if (!with_arg) {
            cmd[strlen(cmd) - 1] = 0;
            argv[0] = cmd;
            int a = fork();
            if (a == 0) {
                argv[1] = NULL;
                execvp(cmd, argv);
            }
            else {
                wait(NULL);
            }
        }
        else {
            int a = fork();
            if (a == 0) {
                execvp(cmd, argv);
            }
            else {
                wait(NULL);
            }
        }
    }
    return 0;
};