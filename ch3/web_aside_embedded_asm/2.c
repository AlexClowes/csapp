#include <limits.h>
#include <stdio.h>

void umult_full(unsigned long x, unsigned long y, unsigned long *dest) {
    asm("movq %[x], %%rax\n\t"
        "mulq %[y]\n\t"
        "movq %%rax, %[lo]\n\t"
        "movq %%rdx, %[hi]\n\t"
        :[lo] "=m" (dest[0]), [hi] "=m" (dest[1])
        :[x] "r" (x), [y] "r" (y)
        : "%rax", "%rdx"
       );
}

int main(void) {
    unsigned long x = ULONG_MAX;
    unsigned long y = 8;
    unsigned long dest[2];
    umult_full(x, y, dest);
    printf("%lx\n", dest[0]);
    printf("%lx\n", dest[1]);
    return 0;
}
