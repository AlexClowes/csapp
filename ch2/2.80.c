#include <limits.h>
#include <stdio.h>

int threefourths(int x) {
    // Get q, r s.t. x = 4 * q + r, 0 <= r < 4.
    int q = x >> 2;
    int r = x - (q << 2);

    // Need to subtract 1 from final result if x >= 0 and r != 0.
    int correction = !(x & INT_MIN) && (r != 0);

    // Result is then 3 * q + r - correction
    return (q << 2) - q + r - correction;
}

int main(void) {
    printf("%d\n", threefourths(-4));
    printf("%d\n", threefourths(-3));
    printf("%d\n", threefourths(-2));
    printf("%d\n", threefourths(-1));
    printf("%d\n", threefourths(0));
    printf("%d\n", threefourths(1));
    printf("%d\n", threefourths(2));
    printf("%d\n", threefourths(3));
    printf("%d\n", threefourths(4));
    return 0;
}
