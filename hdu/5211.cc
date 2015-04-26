#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 10240
using namespace std;
int a[MX], p[MX];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(p, 0, sizeof(p));
        int x = MX, y = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            p[a[i]] = i;
            x = min(x, a[i]);
            y = max(y, a[i]);
        }
        int ans = 0, t;
        for (int i = x; i <= y; ++i) {
            t = MX;
            for (int j = 2; i * j <= y; ++j) {
                if (p[i * j] > p[i])
                    t = min(t, p[i * j]);
            }
            ans += (t == MX ? 0 : t);
        }
        printf("%d\n", ans);
    }
    return 0;
}