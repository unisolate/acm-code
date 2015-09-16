#include <cstdio>
#define MX 1024
using namespace std;
int p[MX][MX], a[MX];
bool f[MX];
int main() {
    int n, m = -1, x, y;
    scanf("%d", &n);
    for (int i = 2; i <= 2 * n; ++i) {
        for (int j = 1; j < i; ++j) {
            scanf("%d", &p[i][j]);
            if (p[i][j] > m) {
                m = p[i][j];
                x = i;
                y = j;
            }
        }
    }
    a[x] = y, a[y] = x;
    f[x] = f[y] = true;
    for (int k = 1; k < n; ++k) {
        m = -1;
        for (int i = 2; i <= 2 * n; ++i) {
            if (f[i])
                continue;
            for (int j = 1; j < i; ++j) {
                if (f[j])
                    continue;
                if (p[i][j] > m) {
                    m = p[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        a[x] = y, a[y] = x;
        f[x] = f[y] = true;
    }
    for (int i = 1; i <= 2 * n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}