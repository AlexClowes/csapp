#include <assert.h>
#include <math.h>

typedef unsigned float_bits;

// Compute -f. If f is NaN, then return f.
float_bits float_negate(float_bits f) {
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && frac != 0) {
        return f;
    }
    return f ^ (1 << 31);
}

float b2f(float_bits x) {
    return *(float*) &x;
}

int main(void) {
    unsigned i = 0;
    do {
        float f = b2f(i);
        float negated = b2f(float_negate(i));
        assert((isnan(f) == isnan(negated)) || (-f == negated));
    } while (++i != 0);
    return 0;
}
