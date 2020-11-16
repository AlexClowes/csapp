#include <assert.h>
#include <math.h>

typedef unsigned float_bits;

// Computer 0.5*f. If f is NaN, then return f.
float_bits float_half(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    // When rounding, round up only if the last two bits of frac are both 1.
    int round_up = (frac & 0x3 == 0x3);

    if (exp == 0xFF) {
        //Nan or +-inf
        return f;
    } else if (exp == 1) {
        // Denormalise
        exp = 0;
        frac = (1 << 22) & (f >> 1) + round_up;
    } else if (exp == 0) {
        // Denormalised
        frac = (frac >> 1) + round_up;
    } else {
        // Everything else
        exp--;
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
        float half_f = b2f(float_half(i));
        assert((isnan(f) == isnan(half_f)) || (0.5 * f == half_f));
    } while (++i != 0);
    return 0;
}
