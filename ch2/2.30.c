/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y) {
    int s = x + y;
    int pos_overflow = (x > 0) && (y > 0) && (s <= 0);
    int neg_overflow = (x < 0) && (y < 0) && (s >= 0);
    return !pos_overflow && !neg_overflow;
}
