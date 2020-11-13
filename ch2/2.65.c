#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise.
   Assume w=32 */
int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

int main(void) {
    int i;
    for (i = 0; i < 16; i++) {
        printf("%d %d\n", i, odd_ones(i));
    }
    return 0;
}
