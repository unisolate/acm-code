#include <cstdio>
#include <cmath>
using namespace std;
int n, k, s, t, x, y, f[102400];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i, k = 0) {
        scanf("%d%d", &x, &y);
        s = sqrt(x), t = i - y;
        for (int j = 1; j < s; ++j)
            if (x % j == 0) {
                if (f[j] < t)
                    ++k;
                if (f[x / j] < t)
                    ++k;
                f[j] = f[x / j] = i;
            }
        if (x % s == 0) {
            if (f[s] < t)
                ++k;
            if (s * s != x && f[x / s] < t)
                ++k;
            f[s] = f[x / s] = i;
        }
        printf("%d\n", k);
    }
    return 0;
}