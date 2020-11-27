// Return minimum of x and y
double dmin(double x, double y) {
    double result;
    asm("vminsd %[x], %[y], %[r]"
        : [r] "=x" (result)
        : [x] "x" (x), [y] "x" (y)
       );
    return result;
}
