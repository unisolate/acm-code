#include <cstdio>
#include <algorithm>
using namespace std;
int p[233];
int main() {
    int t, n, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; ++i) {
            scanf("%d", p + i);
        }
        sort(p, p + n);
        int ans = 0;
        for (int k = 1; k < (1 << n); ++k) {
            int kk = k;
            int x = 0, m = n, c = 0;
            for (int i = 0; i < n; ++i) {
                if (kk & 1) {
                    ++c;
                    x += p[i];
                    if (i < m) {
                        m = i;
                    }
                }
                kk >>= 1;
            }
            if (x >= s && x - p[m] < s) {
                ans = max(ans, c);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}