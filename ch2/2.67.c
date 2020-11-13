/*
   A: The behaviour of left shifts beyond the word length is undefined, per the
      C standard.
*/

/*
   B: Works on machines with int length >= 32.
*/
int int_size_is_32() {
    // Set most significant bit (msb) of 32-bit machine
    int set_msb = 1 << 31;
    // Shift past msb of 32-bit word
    int beyond_msb = set_msb << 1;

    // set_msb is non-zero when word size >= 32
    // beyond_msb is zero when word size <= 32
    return set_msb && !beyond_msb;
}

/*
   C: Works on machines with int length >= 16. (i.e. complies with C standard).
*/
int int_size_is_32() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
