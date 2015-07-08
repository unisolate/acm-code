#include <cstdio>
using namespace std;
int main() {
    long long n, ans = 0, s, k;
    scanf("%lld", &n);
    for (k = 1;; ++k) {
        s = 1;
        for (int i = 0; i < k; ++i)
            s *= 10;
        if (n < s) break;
        int t = 9;
        for (int i = 1; i < k; ++i)
            t *= 10;
        ans += t * k;
    }
    ans += (n - s / 10 + 1) * k;
    printf("%lld\n", ans);
    return 0;
}