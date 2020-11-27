int odd_parity(unsigned long x) {
    int result = 0;
    while (x != 0) {
        char bresult;
        unsigned char bx = x & 0xff;
        asm("testb %[bx], %[bx]\n\t"
            "setnp %[v]"
            : [v] "=r" (bresult)
            : [bx] "r" (bx)
           );
        result ^= (int) bresult;
        x = x >> 8;
    }
    return result;
}
