void *malloc(size_t size);
void *memset(void *s, int c, size_t n);

void *calloc(size_t nmemb, size_t size) {
    size_t buffer_size = nmemb * size;
    if (buffer_size != 0 && nmemb == buffer_size / size) {
        void *p = malloc(buffer_size);
        if (p != NULL) {
            memset(p, 0, buffer_size);
        }
        return p;
    }
    return NULL;
}
