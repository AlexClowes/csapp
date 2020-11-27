#include <assert.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;
typedef unsigned float_bits;

range_t find_range_asm(float x) {
    asm("vxorps %xmm1, %xmm1, %xmm1\n\t"
        "vucomiss %xmm1, %xmm0\n\t"
        "jp .OTHER\n\t"
        "jb .NEG\n\t"
        "je .ZERO\n\t"
        ".POS:\n\t" 
        "movl $2, %eax\n\t"
        "jmp .DONE\n\t"
        ".OTHER:\n\t" 
        "movl $3, %eax\n\t"
        "jmp .DONE\n\t"
        ".NEG:\n\t" 
        "movl $0, %eax\n\t"
        "jmp .DONE\n\t"
        ".ZERO:\n\t" 
        "movl $1, %eax\n\t"
        ".DONE:\n\t" 
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
