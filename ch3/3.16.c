// A:
void goto_cond(long a, long *p) {
    if (p == 0) {
        goto L1;
    }
    if (*p >= a) {
        goto L1;
    }
    *p = a;
L1:
    return;
}

// B:
// We need two conditional branches to allow for short-circuiting the && operator.
// If p == 0, we should skip the check of *p >= a.
