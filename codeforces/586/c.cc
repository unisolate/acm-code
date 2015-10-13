#include <cstdio>
#include <algorithm>
#include <cstring>
#define MX 5000
using namespace std;
int v[MX], d[MX], p[MX], a[MX];
bool f[MX];
int main() {
    int n, k = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        f[i] = true;
        scanf("%d%d%d", v + i, d + i, p + i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!f[i]) {
            continue;
        }
        a[k++] = i;
        f[i] = false;
        int c = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (f[j] && v[i] - c > 0) {
                p[j] -= v[i] - c;
                ++c;
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (f[j] && p[j] < 0) {
                f[j] = false;
                for (int l = j + 1; l <= n; ++l) {
                    if (f[l]) {
                        p[l] -= d[j];
                    }
                }
            }
        }
    }
    printf("%d\n", k);
    for (int i = 0; i < k; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}