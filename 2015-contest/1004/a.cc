#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#define MX 10010
using namespace std;
bitset<MX> bs[11][105], u[12];
struct P {
    int i, s;
    bool f[11];
} p[MX], w[MX];
// int w[MX];
bool cmps(const P &a, const P &b) {
    return a.s > b.s;
}
bool cmpi(P a, P b) {
    return a.i < b.i;
}
int main() {
    int n, k, y, m, a, t, v, h;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        p[i].i = i;
        scanf("%d%d", &p[i].s, &y);
        w[i].s = p[i].s;
        p[i].f[0] = w[i].f[0] = true;
        for (int j = 0; j < y; ++j) {
            scanf("%d", &v);
            p[i].f[v] = w[i].f[v] = true;
        }
    }
    sort(p + 1, p + n + 1, cmps);
    int b = sqrt(n), s = n / b + (n % b ? 1 : 0);
    for (int i = 0; i <= k; ++i) {
        bs[i][0].reset();
        for (int j = 1; j <= s; ++j) {
            bs[i][j] = bs[i][j - 1];
            for (int l = (j - 1) * b + 1; l <= min(j * b, n); ++l) {
                if (p[l].f[i]) {
                    bs[i][j][p[l].i] = 1;
                }
            }
        }
    }
    // sort(p + 1, p + n + 1, cmpi);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &a, &t);
        int z = a;
        p[0].s = w[a].s;
        a = lower_bound(p + 1, p + n + 1, p[0], cmps) - p - 1;
        // printf("#%d\n", a);
        if (a) {
            for (int i = 0; i <= k; ++i) {
                u[i].reset();
            }
            // puts("B");
            u[0] = bs[0][(a - 1) / b];
            // puts("A");
            for (int i = (a - 1) / b * b + 1; i <= a; ++i) {
                if (p[i].f[0]) {
                    u[0][p[i].i] = 1;
                }
            }
            for (int i = 0; i < t; ++i) {
                scanf("%d", &h);
                u[h] = bs[h][(a - 1) / b];
                for (int j = (a - 1) / b * b + 1; j <= a; ++j) {
                    if (p[j].f[h]) {
                        u[h][p[j].i] = 1;
                    }
                }
                if (!w[z].f[h]) {
                    u[h].flip();
                }
                u[0] &= u[h];
            }
        } else {
            u[0].reset();
            for (int i = 0; i < t; ++i) {
                scanf("%d", &h);
            }
        }
        printf("%lu\n", u[0].count() + 1);
    }
    return 0;
}