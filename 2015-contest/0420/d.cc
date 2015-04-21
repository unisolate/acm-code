#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MX 100001
using namespace std;

int f[MX];

int main() {
    int t, cas = 0, n, x, k, s, ans, m;
    scanf("%d", &t);
    while (t--) {
        memset(f, 0, sizeof(f));
        scanf("%d", &n);
        m = 0;
        for (int i = 0; i < n; ++i, k = 0) {
            scanf("%d", &x);
            m = max(m, x);
            s = sqrt(x);
            for (int j = 1; j <= s; ++j)
                if (x % j == 0) {
                    ++f[j];
                    ++f[x / j];
                }
        }
        for (int j = m; j >= 1; --j)
            if (f[j] >= 2) {
                ans = j;
                break;
            }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}