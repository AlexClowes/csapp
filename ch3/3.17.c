// A:
long gotodiff_se(long x, long y) {
    long result;
    if (x < y) {
        goto x_lt_y;
    }
    ge_cnt++;
    result = x - y;
    return result;
x_lt_y:
    lt_cnt++;
    result = y - x;
    return result;
}

// B:
// It doesn't matter in most cases. But if we have no else statement, the first
// choice becomes
//     t = test_expr;
//     if (!t) {
//         goto done;
//     }
//     then-statement;
// done:
// while the second choice becomes
//     t = test_expr;
//     if (t) {
//         goto true;
//     }
//     goto done;
// true:
//     then-statement
// done:
// Which is more complicated for no benefit.
