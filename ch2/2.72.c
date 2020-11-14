// A: The sizeof returns values of type size_t, which are unsigned. So the result
//    of maxbytes - sizeof(val) is also usigned and hence is always >= 0.

// B:
// Copy integer into buffer if space is available
void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= sizeof(val)) {
        memcpy(buf, (void *) &val, sizeof(val));
    }
}
