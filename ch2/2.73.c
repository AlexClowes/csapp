#include <limits.h>
#include <stdio.h>

// Addition that saturates to TMin or TMax
int saturating_add(int x, int y) {
    int sum = x + y;

    // Get sign bits of x, y, x + y
    int sign_mask = INT_MIN;

    int x_non_neg = !(x & sign_mask);
    int y_non_neg = !(y & sign_mask);
    int sum_non_neg = !(sum & sign_mask);

    int pos_overflow = x_non_neg && y_non_neg && !sum_non_neg;
    int neg_overflow = !x_non_neg && !y_non_neg && sum_non_neg;

    (pos_overflow && (sum = INT_MAX)) || (neg_overflow && (sum = INT_MIN));

    return sum;
}

int main(void) {
    printf("%d\n", saturating_add(10, 10));
    printf("%d\n", saturating_add(INT_MAX, 10));
    printf("%d\n", saturating_add(INT_MIN, -10));
    return 0;
}
