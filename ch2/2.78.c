#include <limits.h>
#include <stdio.h>

// Divide by power of 2. Assume 0 <= k < w - 1
int divide_power2(int x, int k) {
    int x_neg = x & INT_MIN;
    x_neg && (x += (1 << k) - 1);
    return x >> k;
}

int main(void) {
    printf("%d\n", divide_power2(7, 2));
    printf("%d\n", divide_power2(-7, 2));
    return 0;
}
