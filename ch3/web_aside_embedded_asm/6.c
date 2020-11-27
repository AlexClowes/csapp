// Return sqrt(x)
double dsqrt(double x) {
    double result;
    asm("sqrtsd %[x], %[r]"
        : [r] "=x" (result)
        : [x] "x" (x)
       );
    return result;
}
