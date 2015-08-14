inline void scanf_(int &num) {
    char in;
    bool neg = false;
    while (((in = getchar()) > '9' || in < '0') && in != '-') ;
    if (in == '-') {
        neg = true;
        while ((in = getchar()) > '9' || in < '0');
    }
    num = in - '0';
    while (in = getchar(), in >= '0' && in <= '9')
        num *= 10, num += in - '0';
    if (neg)
        num = 0 - num;
}
inline void printf_(int num) {
    bool flag = false;
    if (num < 0) {
        putchar('-');
        num = -num;
    }
    int ans[10], top = 0;
    while (num != 0) {
        ans[top++] = num % 10;
        num /= 10;
    }
    if (top == 0)
        putchar('0');
    for (int i = top - 1; i >= 0; i--) {
        char ch = ans[i] + '0';
        putchar(ch);
    }
}