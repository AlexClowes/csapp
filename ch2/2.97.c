#include <assert.h>
#include <limits.h>
#include <stdio.h>

typedef unsigned float_bits;

// Compute (float) i
float_bits float_i2f(int i) {
    unsigned sig;
    unsigned exp;
    unsigned frac;
    unsigned bias = 127;

    // Special cases
    if (i == 0) {
        return 0;
    }
    else if (i == INT_MIN) {
        return (1 << 31) | ((31 + bias) << 23);
    }

    // Get sign of i
    sig = i & (1 << 31);
    // Set i to |i|
    i = sig ? -i : i;

    // exp = (position of highest-order 1 bit in i) + bias
    unsigned i_copy = i;
    exp = 0;
    // This loop over-counts by 1, so subtract 1 at the end
    while (i_copy) {
        i_copy >>= 1;
        exp++;
    }
    exp--;

    // frac is i with highest-order 1 bit removed
    frac = i ^ (1 << exp);
    if (exp <= 23) {
        // Left shift
        frac <<= (23 - exp);
    } else {
        // Right shift - may require rounding
        unsigned shift = exp - 23;
        // Check the bits that are truncated to determine whether rounding is
        // needed
        unsigned lost_bits = frac & ~(-1 << shift);
        unsigned round_up = (lost_bits > (1 << (shift - 1)))
            || (lost_bits == (1 << (shift - 1)) && ((frac >> shift) & 0x1));

        frac = (frac >> shift) + round_up;

        // If frac would overflow a 23-bit unsigned int, then remove highest-
        // -order bit and increment exp
        if (frac & (1 << 23)) {
            frac ^= (1 << 23);
            exp++;
        }
    }

    exp += bias;
    return sig | (exp << 23) | frac;
}

float b2f(float_bits x) {
    return *(float*) &x;
}

int main(void) {
    int i = INT_MIN;
    for (int i = INT_MIN; ; i++) {
        assert((float) i == b2f(float_i2f(i)));
        if (i == INT_MAX) break;
    }
    return 0;
}
