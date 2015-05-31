#include <cstdio>
#define MX 102400
using namespace std;
int a[MX];
int main() {
    int t, n, m, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = a[i], j;
            for (j = i; j < n; ++j) {
                k |= a[j];
                if (k >= m) {
                    // printf("%d %d\n", i, j);
                    ans += j - i;
                    break;
                }
                else if (j == n - 1) ans += j - i + 1;
            }
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}