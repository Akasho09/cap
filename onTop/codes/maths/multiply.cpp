int multiply(int a, int b) {
    int sign = 1;
    if (a < 0) { a = -a; sign = -sign; }
    if (b < 0) { b = -b; sign = -sign; }

    int result = 0;
    while (b > 0) {
        if (b & 1)
            result += a;
        a <<= 1;
        b >>= 1;
    }
    return sign * result;
}
