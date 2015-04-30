#include <cstdio>
#include <algorithm>
#define MX 256
using namespace std;
int n, m, xx, yy;
struct P {
    int id, x, y, b, p;
    int v[MX];
} p[MX];
int abs(int k) {
    return k < 0 ? -k : k;
}
int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int cmp(P a, P b) {
    return a.b < b.b;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        scanf("%d%d", &xx, &yy);
        for (int i = 0; i < n; ++i) {
            p[i].id = i;
            scanf("%d%d%d%d", &p[i].x, &p[i].y, &p[i].b, &p[i].p);
            for (int j = 0; j < m; ++j)
                scanf("%d", &p[i].v[j]);
        }
        sort(p, p + n, cmp);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int r = p[0].v[i];
            for (int j = 1; j < n; ++j) {
                if (p[j].v[i] > r)
                    r = p[j].v[i];
                if (p[j - 1].b + p[j - 1].p + dis(p[j - 1].x, p[j - 1].y, p[j].x,
                                                  p[j].y) > p[j].b)
                    r += p[j].v[i];
            }
            ans += r;
        }
        printf("%d\n", ans);
    }
    return 0;
}