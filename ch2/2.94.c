#include <assert.h>
#include <math.h>

typedef unsigned float_bits;

// Compute 2*f. If f is NaN, then return f.
float_bits float_twice(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF) {
        // Nan or +-inf
        return f;
    } else if (exp == 0xFE) {
        // 2 * f = +-inf
        exp = 0xFF;
        frac = 0;
    } else if (exp == 0) {
        // Denormalised
        frac <<= 1;
    } else {
        // Everything else
        exp++;
    }
    return sig << 31 | exp << 23 | frac;
}

float b2f(float_bits x) {
    return *(float*) &x;
}

int main(void) {
    unsigned i = 0;
    do {
        float f = b2f(i);
        float double_f = b2f(float_twice(i));
        assert((isnan(f) == isnan(double_f)) || (2 * f == double_f));
    } while (++i != 0);
    return 0;
}
