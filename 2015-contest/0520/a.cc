#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int p, a, b, c, d, n;
    while (~scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n)) {
        double ans = -1, v = p * (sin(a + b) + cos(c + d) + 2);
        for (int i = 2; i <= n; ++i) {
            double k = p * (sin(a * i + b) + cos(c * i + d) + 2);
            if (k > v) {
                v = max(v, k);
            }
            if (k < v) {
                ans = max(ans, v - k);
            }
        }
        if (ans < 0) {
            puts("0");
        } else printf("%lf\n", ans);
    }
    return 0;
}