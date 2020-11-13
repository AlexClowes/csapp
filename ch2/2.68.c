#include <stdio.h>
/*
 * Mask with least significant n bits set to 1
 * Examples: n = 6 -> 0x3F, n = 17 -> 0x1FFFF
 * Assume 1 <= n <= w
 */
int lower_one_mask(int n) {
    return (1 << (n - 1) << 1) - 1;
}

int main(void) {
    printf("%X\n", lower_one_mask(6));
    printf("%X\n", lower_one_mask(17));
    printf("%X\n", lower_one_mask(32));
    return 0;
}
