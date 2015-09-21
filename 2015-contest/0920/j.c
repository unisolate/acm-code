#include <stdio.h>
#include <string.h>
#define MX 55555
#define ls l, m, n << 1          // lson
#define rs m + 1, r, n << 1 | 1  // rson
#define lc n << 1                // lchild
#define rc n << 1 | 1            // rchild

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
#define scan_str(s)                                               \
    {                                                             \
        int p = 0;                                                \
        read();                                                   \
        while ((*pt) == ' ' || (*pt) == 'n' || (*pt) == 'r') {    \
            pt++;                                                 \
            read();                                               \
        }                                                         \
        while (!((*pt) == ' ' || (*pt) == 'n' || (*pt) == 'n')) { \
            s[p++] = (*(pt++));                                   \
            read();                                               \
        }                                                         \
        s[p] = 0;                                                 \
    }

int N, M, L, R, LL, RR;
int val[5], num[5][MX], ma[5][MX << 2], mi[5][MX << 2], sum[MX << 2],
    add[MX << 2];
void up(int n) {
    int i;
    for (i = 0; i < 5; ++i) {
        ma[i][n] = ma[i][lc] > ma[i][rc] ? ma[i][lc] : ma[i][rc];
        mi[i][n] = mi[i][lc] < mi[i][rc] ? mi[i][lc] : mi[i][rc];
    }
}
void upans(int n) {
    sum[n] = sum[lc] + sum[rc];
}
void down(int n, int m) {
    if (add[n]) {
        add[lc] = add[rc] = add[n];
        sum[lc] = m - (m >> 1);
        sum[rc] = m >> 1;
        add[n] = 0;
    }
}
// void BB(int l = 1, int r = N, int n = 1) {
//     add[n] = 0;
//     if (l == r) {
//         sum[n] = 0;
//         return;
//     }
//     int m = (l + r) >> 1;
//     BB(ls), BB(rs), upans(n);
// }
void UU(int l, int r, int n) {
    if (LL <= l && r <= RR) {
        add[n] = 1, sum[n] = (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (LL <= m)
        UU(ls);
    if (m < RR)
        UU(rs);
    upans(n);
}
int QQ(int l, int r, int n) {
    if (LL <= l && r <= RR) {
        return sum[n];
    }
    down(n, r - l + 1);
    int ans = 0, m = (l + r) >> 1;
    if (LL <= m)
        ans += QQ(ls);
    if (m < RR)
        ans += QQ(rs);
    return ans;
}
void B(int l, int r, int n) {
    if (l == r) {
        int i;
        for (i = 0; i < 5; ++i) {
            scan(num[i][l]);
            ma[i][n] = mi[i][n] = num[i][l];
        }
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs), up(n);
}
void Q(int l, int r, int n) {
    if (L <= l && r <= R) {
        int f = 1, i;
        for (i = 0; i < 5; ++i) {
            if (mi[i][n] > val[i]) {
                LL = l, RR = r;
                // printf("#%d %d %d\n", i, LL, RR);
                UU(1, N, 1);
                return;
            } else if (ma[i][n] > val[i]) {
                f = 0;
            }
        }
        if (f) {
            return;
        }
    }
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    Q(ls), Q(rs);
}
int main() {
    int t, q;
    scan(t);
    while (t--) {
        scan(N);
        scan(M);
        B(1, N, 1);
        int ans = 0;
        int f = 0;
        scan(q);
        while (q--) {
            // BB();
            // memset(sum, 0, sizeof(sum));
            // memset(add, 0, sizeof(add));
            memset(sum, 0, (N << 2) * sizeof(int));
            memset(add, 0, (N << 2) * sizeof(int));
            int i;
            for (i = 0; i < 5; ++i) {
                scan(val[i]);
                if (f) {
                    val[i] = val[i] ^ ans;
                }
                // printf("%d\n", val[i]);
            }
            L = 1, R = N;
            Q(1, N, 1);
            //
            LL = 1, RR = N;
            ans = N - QQ(1, N, 1);
            printf("%d\n", ans);
            // putchar(10);
            f = 1;
        }
    }
    return 0;
}