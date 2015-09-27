#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 100010
using namespace std;
struct P {
    int h, k;
} p[MX];
int cmp(P a, P b) {
    return a.h < b.h;
}
int v[MX], a[MX];
void U(int x) {
    for (; x < MX; x += (x & -x))
        ++v[x];
}
int Q(int x) {
    int r = 0;
    for (; x > 0; x -= (x & -x))
        r += v[x];
    return r;
}
int main() {
    int t, n, c = 0;
    scanf("%d", &t);
    while (t--) {
        memset(v, 0, sizeof(v));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &p[i].h, &p[i].k);
        }
        sort(p + 1, p + n + 1, cmp);
        printf("Case #%d: ", ++c);
        bool f = true;
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = n + 1, m, y, z;
            while (l <= r) {
                m = (l + r) >> 1;
                if (m - Q(m) < p[i].k + 1) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            y = l;
            l = 1, r = n + 1;
            while (l <= r) {
                m = (l + r) >> 1;
                if (n + 1 - m - Q(n) + Q(m - 1) >= p[i].k + 1) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            z = r;
            m = min(y, z);
            if (m > n) {
                f = false;
                break;
            }
            // printf("%d %d\n", y, z);
            if (m == 0) {
                f = false;
                break;
            }
            U(m);
            a[m] = p[i].h;
        }
        if (f) {
            printf("%d", a[1]);
            for (int i = 2; i <= n; ++i) {
                printf(" %d", a[i]);
            }
            puts("");
        } else {
            puts("impossible");
        }
    }
    return 0;
}