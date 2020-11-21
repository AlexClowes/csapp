// A:
long fun_b(unsigned long x) {
    long val = 0;
    long i;
    for (i = 64; i != 0; i--) {
        val = (val << 1) | (x & 1);
        x >> 1;
    }
    return val;
}

// B:
// At the start of the loop, i = 64, so there is always at least one iteration of
// the loop. This means we don't require an initial test or jump before the loop.

// C:
// fun_b(x) returns the long obtained by reversing the bits of x.
