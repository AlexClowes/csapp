// Let x, y be unsigned integers represented by w-bit binary vectors [x_w-1, ... x_0]
// and [y_w-1, ..., y_0] respectively. Let x' and y' be the signed integers represented
// by the same w-bit binary vectors.
// Then x' = x - 2^w * x_w-1 and y' = y - 2^w * y_w-1
//   => x' * y' = (x - 2^w * x_w-1) * (y - 2^w * y_w-1)
//              = x * y - 2^w * (x_w-1 * y + y_w-1 * x) + 2^2w * x_w-1 * y_w-1
// Working modulo 2^2w, we see that the high-order w bits of x * y are the same as
// the high-order w bits of
//   x' * y' + 2^w * (x_w-1 * y + y_w-1 * x)
// = x' * y' + (x_w-1 * y + y_w-1 * x) << w

int signed_high_prod(int x, int y);

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned nbits = sizeof(unsigned) << 3
    unsigned high_bit_mask = 1 << (nbits - 1);
    unsigned x_high_bit = (x & high_bit_mask) >> (nbits - 1);
    unsigned y_high_bit = (y & high_bit_mask) >> (nbits - 1);

    return signed_high_prod(x, y) + (x_high_bit * y) + (y_high_bit * x);
}
