#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; ++i) {
        void *x = malloc(1000*1024*10);
        memset(x, 1, 1000*1024*10);
        struct rusage *usage = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, usage);
        printf("CPU time\tMax resident set size\tShared memory\tUnshared data\tUnshared stack\t\n");
        printf("%ld\t%ld\t%ld\t\t\t%ld\t\t%ld\t\t%ld\t\n",
               usage->ru_stime.tv_usec, usage->ru_stime.tv_usec, usage->ru_maxrss,
               usage->ru_ixrss, usage->ru_idrss, usage->ru_isrss);
        sleep(1);
    }
    return 0;
}