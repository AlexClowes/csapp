#include <stdio.h>
// Return 1 when x can be represented as an n-bit, 2's-complement number; 0 otherwise.
// Assume 1 <= n <= w
int fits_bits(int x, int n) {
    int nbits = sizeof(int) << 3;
    return !((x >> (n - 1)) - (x >> (nbits - 1)));
}


int main(void) {
    printf("%d\n", fits_bits(256, 8));
    printf("%d\n", fits_bits(-256, 8));

    printf("%d\n", fits_bits(127, 8));
    printf("%d\n", fits_bits(-128, 8));
    return 0;
}
