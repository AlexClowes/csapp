#include <limits.h>
#include <stdio.h>

int mul3div4(int x) {
    // multiply by 3
    x = (x << 2) - x;
    // divide by 4
    int x_neg = x & INT_MIN;
    x_neg && (x += (1 << 2) - 1);
    return x >> 2;
}

int main(void) {
    printf("%d\n", mul3div4(11));
    printf("%d\n", mul3div4(-11));
    return 0;
}
