#include <limits.h>
#include <stdio.h>
// Determine whether arguments can be subtracted without overflow
int tsub_ok(int x, int y) {
    int diff = x - y;

    int sign_mask = INT_MIN;
    int x_non_neg = !(x & sign_mask);
    int y_non_neg = !(y & sign_mask);
    int diff_non_neg = !(diff & sign_mask);

    // Positive overflow if x >= 0, y < 0, x - y < 0.
    int pos_overflow = x_non_neg && !y_non_neg && !diff_non_neg;
    // Negative overflow if x < 0, y >= 0, x - y >= 0.
    int neg_overflow = !x_non_neg && y_non_neg && diff_non_neg;

    return pos_overflow || neg_overflow;
}


int main(void) {
    printf("%d\n", tsub_ok(0, INT_MIN));  // Expect 1
    printf("%d\n", tsub_ok(0, 0));        // Expect 0
    return 0;
}
