long cread_alt(long *xp) {
    long zero = 0;
    long *p = xp ? xp : &zero;
    return *p;
}
