#include <cstdio>
#define MX 100005
using namespace std;
int n, m, p[MX], v[MX];
int f(int x) {
    return x == p[x] ? x : (p[x] = f(p[x]));
}
void u(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return;
    p[x] = y;
    v[y] += v[x];
    v[x] = 0;
}
int main() {
    int o, x, y;
    while (scanf("%d%d", &n, &m) && n + m) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &v[i]);
            p[i] = i;
        }
        int ans = 0;
        while (m--) {
            scanf("%d%d%d", &o, &x, &y);
            if (o == 1) {
                u(x, y);
            } else {
                if (f(1) == f(x) && v[f(x)] > v[f(y)])
                    ++ans;
                if (f(1) == f(y) && v[f(x)] < v[f(y)])
                    ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}