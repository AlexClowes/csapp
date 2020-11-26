#include <stdio.h>
#define BUFSIZE 256

void good_echo() {
    char buf[BUFSIZE];
    while (fgets(buf, BUFSIZE, stdin)) {
        printf("%s", buf);
    }
    printf("\n");
}
