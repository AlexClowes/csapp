#include <stdio.h>
/* Return 1 when any odd bit of x equals 1; 0 otherwise.
   Assume w=32 */
int any_odd_one(unsigned x) {
    return !!(x & 0xAAAAAAAA);
}

int main(void) {
    printf("%d\n", any_odd_one(0));  // Expect 0
    printf("%d\n", any_odd_one(1));  // Expect 0
    printf("%d\n", any_odd_one(2));  // Expect 1
    printf("%d\n", any_odd_one(3));  // Expect 1
    printf("%d\n", any_odd_one(4));  // Expect 0
    printf("%d\n", any_odd_one(5));  // Expect 0
    printf("%d\n", any_odd_one(6));  // Expect 1
    printf("%d\n", any_odd_one(7));  // Expect 1
    return 0;
}
