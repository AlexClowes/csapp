// A:
// x is stored in register %rdi.
// n is stored in register %ecx.
// result is stored in register %rax.
// mask is stored in register %rdx.

// B:
// result has initial value 0.
// mask has initial value 1.

// C:
// The test condition is mask != 0.

// D:
// Mask is updated by left-shifting it by n.
// i.e. mask <<= n

// E:
// result is updated by setting result = (x & mask) | result.

// F:
long loop(long x, int n) {
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask = mask << n) {
        result |= x & mask;
    }
    return result;
}
