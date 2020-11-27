void lock_incr(int *ptr) {
    asm("lock\n\t"
        "addl $1 %[p]"
        : [p] "+m" (*ptr)
       );
}
