#include <stdio.h>
#include <math.h>

float u2f(unsigned u) {
    return *(float *) &u;
}

float fpwr2(int x) {
    // Result exponent and fraction
    unsigned exp, frac;
    unsigned u;

    if (x < -149) {
        // Too small. Return 0.0
        exp = 0;
        frac = 0;
    } else if (x < -126) {
        // Denormalised result
        exp = 0;
        frac = 1 << (x + 149);
    } else if (x < 128) {
        // Normalised result
        exp = x + 127;
        frac = 0;
    } else {
        // Too big. Return +inf
        exp = 255;
        frac = 0;
    }

    // Pack exp and frac into 32 bits
    u = exp << 23 | frac;
    // Return as float
    return u2f(u);
}

int main(void) {
    printf("%d\n", fpwr2(-150) == 0.0);
    printf("%d\n", fpwr2(-130) == powf(2, -130));
    printf("%d\n", fpwr2(20) == powf(2, 20));
    printf("%d\n", fpwr2(130) == powf(2, 130));
    return 0;
}
