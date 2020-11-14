// A: The given code does not perform the sign extension correctly.
//    For example, xbyte(0xFF, 0) would return 255, but it should return -1.

// B:
#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    int byte_pos = bytenum << 3;
    return (int) (word & (0xFF << byte_pos)) << (24 - byte_pos) >> 24;
}


int main(void) {
    printf("%d\n", xbyte(0xFF, 0));    // Expect -1
    printf("%d\n", xbyte(0x0FFF, 1));  // Expect 15
    return 0;
}
