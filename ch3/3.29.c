// A:
// Naively applying the translation rule results in the following:
long sum = 0;
long i = 0;
while (i < 10) {
    if (i & 1) {
        continue;
    }
    sum += i;
    i++;
}
// Executing the continue statement would skip the i++ statement, and cause the
// code to enter an infinite loop.

// B:
long sum = 0;
long i = 0;
while (i < 10) {
    if (i & 1) {
        goto upd;
    }
    sum += i;
upd:
    i++;
}
