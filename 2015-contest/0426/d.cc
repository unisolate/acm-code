#include <cstdio>
#include <cstring>
using namespace std;
int p[102400], k[1024000];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        memset(k, 0, sizeof(k));
        long long ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; ++i) {
            ans += (long long)p[i] * ((n - i + 1) * (i - k[p[i]]));
            k[p[i]] = i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}