#include <cstdio>
#include <cstring>
#define MX 128
using namespace std;
int m, n, p[MX][MX], f[MX][MX];
int a[] = {1, 1, 0, -1, -1, -1, 0, 1};
int b[] = {0, 1, 1, 1, 0, -1, -1, -1};
char s[MX][MX];
void d(int x, int y, int k) {
    for (int i = 0; i < 8; ++i) {
        int u = x + a[i], v = y + b[i];
        if (u >= 0 && u < m && v >= 0 && v < n && s[u][v] == '@' && !f[u][v])
            p[u][v] = k, f[u][v] = 1, d(u, v, k);
    }
}
int main() {
    while (scanf("%d%d", &m, &n) && m) {
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));
        for (int i = 0; i < m; ++i)
            scanf("%s", s[i]);
        int k = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (s[i][j] == '@' && !p[i][j])
                    d(i, j, ++k);
        printf("%d\n", k);
    }
    return 0;
}