// A:
// Jump-to-middle loop translation is used.

// B:
long fun_a(unsigned long x) {
    long val = 0;
    while (x != 0) {
        val = val ^ x;
        x = x >> 1;
    }
    return val & 1;
}

// C:
// fun_a(x) computes the parity of the unsigned long x.
