long switch_prob(long x, long n) {
    long result = x;
    switch(n) {
        case 60:
        case 62:
            result = 8 * x;
            break;
        case 63:
            result = x >> 3;
            break;
        case 64:
            x = 15 * x;
            // Fall through
        case 65:
            x *= x;
            // Fall through
        case default:
            result = x + 75;
    }
    return result;
}
