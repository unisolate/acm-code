#include <cstdio>
#include <cstring>
#include <algorithm>
#define EPS 0.00001
using namespace std;

struct T {
    int d, r;
    double s;
} p[128];

int n, q, s, c, a, u, x, y, z;
int f[128][16][128];
int v[16][128];

int cmp1(T ta, T tb) {
    return ta.s > tb.s;
}

int cmp2(T ta, T tb) {
    return ta.d < tb.d;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &q, &s, &c);
        for (int i = 0; i < n; ++i) {
            p[i].d = i + 1;
            p[i].s = s;
        }

        while (c--) {
            memset(f, 0, sizeof(f));
            scanf("%d", &a);
            for (int i = 0; i < a; ++i) {
                scanf("%d%d%d", &x, &y, &z);
                f[y - 1][z - 1][x - 1] = 1;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < q; ++j) {
                    int cnt = 0;
                    for (int k = 0; k < n; ++k) {
                        if (f[i][j][k]) ++cnt;
                    }
                    if (cnt == 0)
                        continue;

                    p[i].s -= n - 1;
                    for (int k = 0; k < n; ++k) {
                        if (f[i][j][k])
                            p[k].s += (double)(n - 1) / cnt;
                    }
                }
            }

            memset(v, 0, sizeof(v));
            for (int i = 0; i < q; ++i) {
                for (int j = 0; j < n; ++j) {
                    scanf("%d", &x);
                    if (x == 0) v[i][j] = 1;
                }
            }
            for (int i = 0; i < q; ++i) {
                int cnt = 0;
                for (int j = 0; j < n; ++j) {
                    if (v[i][j]) ++cnt;
                }
                if (cnt == 0)
                    continue;

                for (int j = 0; j < n; ++j) {
                    if (!v[i][j]) {
                        p[j].s += (double)cnt * (n - 1) / (n - cnt);
                    } else p[j].s -= n - 1;
                }
            }

            sort(p, p + n, cmp1);
            p[0].r = 1;
            for (int i = 1; i < n; ++i) {
                if (p[i - 1].s - p[i].s < EPS)
                    p[i].r = p[i - 1].r;
                else p[i].r = i + 1;
            }
            sort(p, p + n, cmp2);
            scanf("%d", &u);
            for (int i = 0; i < u; ++i) {
                scanf("%d", &x);
                printf("%.8lf %d\n", p[x - 1].s, p[x - 1].r);
            }
        }
    }
    return 0;
}