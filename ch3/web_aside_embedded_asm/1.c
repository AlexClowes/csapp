#include <limits.h>
#include <stdio.h>

int tmult_ok(long x, long y, long *dest) {
    unsigned char bresult;
    asm("imulq %[x], %[y]\n\t"
        "setae %[b]"
        : [y] "+r" (y), [b] "=r" (bresult)
        : [x] "r" (x)
       );
    *dest = y;
    return (int) bresult;
}

int main(void) {
    long prod;
    int ok;

    ok = tmult_ok(-10L, 20L, &prod);
    printf("product = %ld, ok = %d\n", prod, ok);

    ok = tmult_ok(LONG_MAX, 20L, &prod);
    printf("product = %ld, ok = %d\n", prod, ok);

    return 0;
}
