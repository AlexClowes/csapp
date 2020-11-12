#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian() {
    int i = 1;
    byte_pointer ip = (byte_pointer) &i;
    return *ip == 0;
}

int main(void) {
    printf("%d\n", is_little_endian());
}
