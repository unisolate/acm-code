#include <cstdio>
#include <algorithm>
using namespace std;
int a[128], p[128][128];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            p[j][i] += a[i] / k;
            if (a[i] % k > j)
                ++p[j][i];
        }
    }
    bool f = true;
    for (int i = 0; i < k; ++i) {
        sort(p[i], p[i] + n);
        if (p[i][n - 1] - p[i][0] > 1)
            f = false;
    }
    if (f) {
        puts("YES");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a[i]; ++j) {
                printf("%d ", j % k + 1);
            }
            putchar(10);
        }
    } else puts("NO");
    return 0;
}