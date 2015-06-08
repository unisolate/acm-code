#include <cstdio>
using namespace std;
char s[111][111];
int p[111][111];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j)
            p[i][j] = (s[i][j] == 'B' ? 1 : -1);
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (p[i][j] != 0) {
                ++ans;
                int t = p[i][j];
                for (int k = 0; k <= i; ++k)
                    for (int l = 0; l <= j; ++l)
                        p[k][l] -= t;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}