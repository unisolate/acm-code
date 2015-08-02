#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 0.000001
#define MX 1000001
using namespace std;
typedef long long ll;
int t, n, x, y, p[MX];
int u(int k) {
    int c = 1, d = p[k + 1] - p[k];
    while (k < n - 1 && p[k + 1] - p[k] == d) {
        ++c;
        ++k;
    }
    x = k - 1;
    return c;
}
int v(int k) {
    int c = 1;
    double d = (double)p[k + 1] / p[k];
    while (k < n - 1 && abs((double)p[k + 1] / p[k] - d) < eps) {
        ++c;
        ++k;
    }
    y = k - 1;
    return c;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", p + i);
        int ans = 1;
        x = y = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i >= x)
                ans = max(ans, u(i));
            if (i >= y)
                ans = max(ans, v(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}