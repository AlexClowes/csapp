#include <assert.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned float_bits;

// Compute |f|. If f is NaN, then return f.
float_bits float_absval(float_bits f) {
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && frac != 0) {
        return f;
    }
    return f & ~(1<<31);
}

float b2f(float_bits x) {
    return *(float*) &x;
}

int main(void) {
    unsigned i = 0;
    do {
        float f = b2f(i);
        float abs_f = b2f(float_absval(i));
        assert((isnan(f) == isnan(abs_f)) || (abs(f) == abs_f));
    } while (++i != 0);
    return 0;
}
