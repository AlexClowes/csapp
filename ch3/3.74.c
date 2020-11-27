#include <assert.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;
typedef unsigned float_bits;

range_t find_range_asm(float x) {
    asm("vxorps %xmm1, %xmm1, %xmm1\n\t"
        "vucomiss %xmm1, %xmm0\n\t"
        "movl $0, %r8d\n\t"
        "movl $1, %r9d\n\t"
        "movl $2, %eax\n\t"
        "movl $3, %r11d\n\t"
        "cmovel %r9d, %eax\n\t"
        "cmovbl %r8d, %eax\n\t"
        "cmovpl %r11d, %eax\n\t"
       );
}

range_t find_range_c(float x) {
    int result;
    if (x < 0)
        result = NEG;
    else if (x == 0)
        result = ZERO;
    else if (x > 0)
        result = POS;
    else
        result = OTHER;
    return result;
}

int main(void) {
    union {
        unsigned i;
        float f;
    } u;
    u.i = 0;
    do {
        assert(find_range_asm(u.f) == find_range_c(u.f));
    } while (++u.i != 0);
    return 0;
}
