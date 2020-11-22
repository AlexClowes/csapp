#define N 16
typedef int fix_matrix[N][N];

void fix_set_diag_opt(fix_matrix A, int val) {
    int *Aptr = &A[0][0];
    long i = 0;
    long iend = N * (N + 1);
    do {
        *(Aptr + i) = val;
        i += N + 1;
    } while (i != iend);
}
