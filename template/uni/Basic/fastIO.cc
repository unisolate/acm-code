// 1. fread + 缓冲区法
#define BUFSIZE 1000000
char buf[BUFSIZE], *pt = buf + BUFSIZE, *pend = buf + BUFSIZE;
int sign;
#define read()                             \
    do {                                   \
        if (pt >= pend) {                  \
            pt = buf;                      \
            fread(buf, 1, BUFSIZE, stdin); \
        }                                  \
    } while (0)
#define scan(t)                                          \
    {                                                    \
        t = 0;                                           \
        sign = 1;                                        \
        read();                                          \
        while ((*pt < '0' || *pt > '9') && *pt != '-') { \
            pt++;                                        \
            read();                                      \
        }                                                \
        if (*pt == '-')                                  \
            sign = -1, pt++;                             \
        while (((*pt) >= '0' && (*pt) <= '9')) {         \
            t = t * 10 + (*(pt++)) - '0';                \
            read();                                      \
        }                                                \
        t *= sign;                                       \
    }
#define scan_str(s)                                      \
    {                                                    \
        int p = 0;                                       \
        read();                                          \
        while ((*pt) == ' ' || (*pt) == 'n' || (*pt) == 'r') { \
            pt++;                                        \
            read();                                      \
        }                                                \
        while (!((*pt) == ' ' || (*pt) == 'n' || (*pt) == 'n')) { \
            s[p++] = (*(pt++));                          \
            read();                                      \
        }                                                \
        s[p] = 0;                                        \
    }

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