#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#define MX 150005
using namespace std;
struct P {
    char s[205];
    int i, v;
} p[MX];
struct Q {
    int t, p;
} q[MX];
int cmpq(Q a, Q b) {
    return a.t < b.t;
}
int cmpp(P a, P b) {
    if (a.v == b.v)
        return a.i < b.i;
    return a.v > b.v;
}
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
int main() {
    int T, k, m, n, t, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &k, &m, &t);
        for (int i = 1; i <= k; ++i) {
            scanf("%s", p[i].s);
            scanf_(p[i].v);
            p[i].i = i;
        }
        for (int i = 0; i < m; ++i) {
            scanf_(q[i].t);
            scanf_(q[i].p);
        }
        q[m].t = k, q[m].p = k;
        sort(q, q + m + 1, cmpq);
        int cnt = 0, pos = 0;
        for (int i = 0; i < t; ++i) {
            scanf_(n);
            while (n > cnt) {
                if (pos + 1 <= m && q[pos].t == q[pos + 1].t) {
                    q[pos + 1].p += q[pos].p;
                    ++pos;
                    continue;
                }
                sort(p + cnt + 1, p + q[pos].t + 1, cmpp);
                cnt = min(cnt + q[pos].p, q[pos].t);
                ++pos;
            }
            printf("%s%c", p[n].s, (i == t - 1) ? '\n' : ' ');
        }
    }
    return 0;
}