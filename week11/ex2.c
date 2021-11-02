#include <stdio.h>
#include <dirent.h>

int main ()
{
    DIR *direct;
    struct dirent *x;

    direct = opendir("/");

    if (direct == NULL) {
        printf("Cannot open root directory");
        return 0;
    }

    while ((x = readdir(direct)) != NULL) {
        puts(x->d_name);
    }
    closedir(direct);

    return 0;
}