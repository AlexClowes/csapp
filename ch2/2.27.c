/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y) {
    return (x + y) >= x;
}
