#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
struct P {
    int x, w;
} p[10000001];
int cmp(P a, P b) {
    return a.x > b.x;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i].x);
        }
        long long s = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i].w);
            s += p[i].w;
        }
        double m = (double)s / 2;
        sort(p, p + n, cmp);
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && p[i].x == p[i + 1].x) {
                p[i + 1].w += p[i].w;
                continue;
            }
            if (s - p[i].w - k < m && k <= m) {
                printf("%d\n", p[i].x);
                break;
            }
            k += p[i].w;
        }
    }
    return 0;
}