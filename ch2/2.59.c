#include <stdio.h>

size_t combine_words(size_t x, size_t y) {
    return (x & 0xFF) | (y & ~0xFF);
}

int main(void) {
    printf("%zX\n", combine_words(0x89ABCDEF, 0x765432EF));
    return 0;
}
