#include <cstdio>
#include <algorithm>
#define MX 3333
using namespace std;
int n, t;
struct P {
    int t, s;
    double r;
} p[MX];
int cmp(P a, P b) {
    return a.r < b.r;
}
int main() {
    while (~scanf("%d%d", &n, &t)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &p[i].t, &p[i].s);
            p[i].r = (double)p[i].t / p[i].s;
        }
        sort(p, p + n, cmp);
        int ans = 0, v = 0;
        while (t > 0) {
            if (t > p[v].t)
                ans += t * p[v].s;
            t -= p[v].t;
            ++v;
        }
        printf("%d\n", ans);
    }
    return 0;
}