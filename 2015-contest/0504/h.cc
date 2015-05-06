#include <cstdio>
#include <algorithm>
using namespace std;
int sum(int x, int y) {
    int r = 0;
    for (int i = x; i <= y; ++i)
        r += i;
    return r;
}
int main() {
    int m, n;
    while (~scanf("%d%d", &m, &n)) {
        int ans = 0, k = m * (m - 1) / 2;
        for (int i = 1; i <= m; ++i) {
            int t = 0;
            if (i % 2) {
                t = sum(i, m);
                int u = (n - m + i - 1) / m, v = (n - m + i - 1) % m;
                t += k * u;
                if (v) {
                    if (u % 2) {
                        t += sum(1, v);
                    } else {
                        t += sum(m - v + 1, m);
                    }
                }
                printf("#%d %d %d %d\n", i, u, v, t);
            } else {
                t = sum(1, i);
                int u = (n - i) / m, v = (n - i) % m;
                t += k * u;
                if (v) {
                    if (u % 2) {
                        t += sum(m - v + 1, m);
                    } else {
                        t += sum(1, v);
                    }
                }
                printf("##%d %d %d %d\n", i, u, v, t);
            }
            ans = max(ans, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}