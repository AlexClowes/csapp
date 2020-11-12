#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    int shift = i * 8;
    return (x & ~(0xFF << shift)) | (b << shift);
}


int main(void) {
    printf("%X\n", replace_byte(0x12345678, 2, 0xAB));
    printf("%X\n", replace_byte(0x12345678, 0, 0xAB));
}
