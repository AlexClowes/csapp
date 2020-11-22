// A:
struct ELE {
    long v;
    struct ELE *p;
}

long fun(struct ELE *ptr) {
    long ret = 0;
    while (ptr) {
        ret += ptr->v;
        ptr = ptr->p;
    }
    return ret;
}

// B:
// The struct ELE is a node of a linked list. The operation fun sums all the
// values in a linked list.
