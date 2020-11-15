#include <stdio.h>

unsigned f2u(float x) {
    return *(unsigned *) &x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    // Get the sign bits
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    // Give an expression using only ux, uy, sx and sy
    return (!sx && !sy && ux <= uy)     // 0 <= x <= y
        || (sx && !sy)                  // x < 0 <= y
        || (sx && sy && ux >= uy)       // x <= y < 0
        || (!(ux << 1) && !(uy << 1));  // x = y = 0
}

int main(void) {
    printf("%d\n", float_le(-0., 0.));
    printf("%d\n", float_le(-2., 1.));
    printf("%d\n", float_le(-2., -1.));
    printf("%d\n", float_le(1., 2.));
    return 0;
}
