#include <cstdio>
#include <bitset>
#include <cmath>
#include <algorithm>
#define MX 50005
#define MY 233
using namespace std;
struct A {
    int i, v;
} a[5][MX];
bitset<MX> s[5][MY], r[5];
bool cmp(const A &x, const A &y) {
    return x.v < y.v;
}
int main() {
    int t, n, m, q;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 5; ++j) {
                scanf("%d", &a[j][i].v);
                a[j][i].i = i;
            }
        }
        int v = sqrt(n), b = n / v + (n % v ? 1 : 0);
        for (int i = 0; i < 5; ++i) {
            sort(a[i] + 1, a[i] + n + 1, cmp);
            s[i][0].reset();
            for (int j = 1; j <= b; ++j) {
                s[i][j] = s[i][j - 1];
                for (int k = (j - 1) * v + 1; k <= min(j * v, n); ++k) {
                    s[i][j][a[i][k].i] = 1;
                }
            }
        }
        int ans = 0;
        scanf("%d", &q);
        while (q--) {
            for (int i = 0; i < 5; ++i) {
                scanf("%d", &a[i][0].v);
                a[i][0].v ^= ans;
                r[i].reset();
            }
            for (int i = 0; i < 5; ++i) {
                int p = upper_bound(a[i] + 1, a[i] + n + 1, a[i][0], cmp) -
                        a[i] - 1;
                if (p == 0) {
                    continue;
                }
                r[i] = s[i][(p - 1) / v];
                for (int j = (p - 1) / v * v + 1; j <= p; ++j) {
                    r[i][a[i][j].i] = 1;
                }
            }
            printf("%d\n", ans = (r[0] & r[1] & r[2] & r[3] & r[4]).count());
        }
    }
    return 0;
}