#include <stdio.h>

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    // Now set highest-order k bits to 0
    unsigned nbits = (sizeof(unsigned) << 3);
    unsigned mask = (1 << (nbits - k)) - 1;
    return xsra & mask;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    // Now set highest-order k bits to match highest-order bit of x
    int nbits = (sizeof(int) << 3);
    int high_bit = !!(x & (1 << (nbits - 1)));
    int mask = ~((high_bit << (nbits - k)) - 1);
    return xsrl | mask;
}

int main(void) {
    // Logical right shift
    printf("%X\n", srl(16, 3));  // Expect 0x2
    printf("%X\n", srl(-16, 3)); // Expect 0x1FFFFFFE

    // Arithmetic right shift
    printf("%X\n", sra(16, 3));  // Expect 0x2
    printf("%X\n", sra(-16, 3)); // Expect 0xFFFFFFFE
    return 0;
}
