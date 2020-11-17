#include <assert.h>
#include <stdio.h>

typedef unsigned float_bits;

// Compute (int) f.
// If conversion causes overflow or f is NaN, return 0x80000000
int float_f2i(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp <= 126) {
        // |f| < 1
        return 0;
    } else if (exp <= 150) {
        // Right shift frac
        frac = ((1 << 23) | frac) >> (150 - exp);
    } else if (exp <= 157) {
        // Left shift frac
        frac = ((1 << 23) | frac) << (exp - 150);
    } else {
        // Overflow
        return 0x80000000;
    }

    if (sig) {
        // Negative numbers
        frac = 1 + ~frac;
    }
    return frac;
}


float b2f(float_bits x) {
    return *(float*) &x;
}

int main(void) {
    unsigned i = 0;
    do {
        assert((int) b2f(i) == float_f2i(i));
    } while (++i != 0);
    return 0;
}
