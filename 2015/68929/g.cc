#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a = 10240 * 128;
char s[128][10240];
int p[128][10240];
int main() {
    bool f = true;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) {
        int u = -1, v = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '1') {
                p[i][j] = 0;
                if (u >= 0) {
                    for (int k = u + 1; k < j; ++k)
                        p[i][k] = min(k - u, j - k);
                } else v = j;
                u = j;
            }
        }
        if (u == -1) {
            f = false;
            break;
        } else {
            for (int k = u + 1; k < v + m; ++k)
                p[i][k % m] = min(k - u, v + m - k);
        }
    }
    for (int j = 0; j < m; ++j) {
        int v = 0;
        for (int i = 0; i < n; ++i)
            v += p[i][j];
        a = min(a, v);
    }
    if (f)
        printf("%d", a);
    else puts("-1");
    return 0;
}