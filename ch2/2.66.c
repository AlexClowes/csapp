#include <stdio.h>
/*
 * Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 -> 0x4000.
 * If x = 0, then return 0.
 */
int leftmost_one(unsigned x) {
    // Transform bit pattern 0...01x...x -> 0...01...1.
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);

    // Remove all but leftmost 1
    return x ^ (x >> 1);
}

int main(void) {
    printf("%X\n", leftmost_one(0xFF00));  // Expect 0x8000
    printf("%X\n", leftmost_one(0x6600));  // Expect 0x4000
    return 0;
}
