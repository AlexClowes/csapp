#include <stdio.h>

/*
 * Do rotating left shift. Assume 0 <= n < w.
 * Examples when x = 0x12345678 and w = 32:
 *    n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n) {
    int nbits = (sizeof(int) << 3);
    return (x >> (nbits - n)) | (x << n);
}

int main(void) {
    printf("%X\n", rotate_left(0x12345678, 4));
    printf("%X\n", rotate_left(0x12345678, 20));
    printf("%X\n", rotate_left(0x12345678, 0));
    return 0;
}
