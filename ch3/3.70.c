// A:
// Field  Offset
// e1.p   0
// e1.y   8
// e2.x   0
// e3.y   8

// B:
// The structure requires 16 bytes in total.

// C:
void proc(union ele *up) {
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;
}
