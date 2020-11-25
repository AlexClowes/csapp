long decode2(long x, long y, long z) {
    long temp = y - z;
    return (temp * x) ^ (temp << 63 >> 63);
}
