#include <cstdio>
#include <algorithm>
#define MX 44444
using namespace std;
int x[MX], y[MX];
int main() {
    freopen("defense.in", "r", stdin);
    freopen("defense.out", "w", stdout);
    int w, h, n;
    scanf("%d%d%d", &w, &h, &n);
    x[0] = y[0] = 0;
    x[n + 1] = w + 1;
    y[n + 1] = h + 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", x + i, y + i);
    }
    sort(x, x + n + 1);
    sort(y, y + n + 1);
    int a = 0, b = 0;
    for (int i = 0; i <= n; ++i) {
        a = max(a, x[i + 1] - x[i] - 1);
        b = max(b, y[i + 1] - y[i] - 1);
    }
    printf("%d\n", a * b);
    return 0;
}