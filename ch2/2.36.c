/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
    int64_t p = (int64_t) x * y;
    // Now just check that product remains the same if we cast it to int.
    return p = (int) p;
}
