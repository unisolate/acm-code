// 1. fread + 缓冲区法
struct FastIO {
    static const int S = 131072;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {
    }
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len)
            return -1;
        return buf[pos++];
    }
    inline int xuint() {
        int s;
        scanf("%d", &s);
        return s;
        int c = xchar(), x = 0;
        while (c <= 32)
            c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar())
            x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int t;
        scanf("%d", &t);
        return t;
        int s = 1, c = xchar(), x = 0;
        while (c <= 32)
            c = xchar();
        if (c == '-')
            s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar())
            x = x * 10 + c - '0';
        return x * s;
    }
    ~FastIO() {
        if (wpos)
            fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;

// 2. naive
inline void scanf_(int &num) {
    char in;
    bool neg = false;
    while (((in = getchar()) > '9' || in < '0') && in != '-')
        ;
    if (in == '-') {
        neg = true;
        while ((in = getchar()) > '9' || in < '0')
            ;
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