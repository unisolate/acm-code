#include <cstdio>
#include <cstring>
#define MX 105
using namespace std;
char s[3][MX];
int n, f[3][MX];
int dfs(int l, int x) {
    if (f[l][x] != -1) {
        return f[l][x];
    }
    f[l][x] = 0;
    if (x + 1 >= n) {
        return f[l][x] = 1;
    }
    if (s[l][x + 1] != '.') {
        return 0;
    }
    for (int i = -1; i <= 1; ++i) {
        if (l + i < 0 || l + i > 2) {
            continue;
        }
        if (s[l + i][x + 1] == '.' && (x + 2 >= n || s[l + i][x + 2] == '.') &&
            (x + 3 >= n || s[l + i][x + 3] == '.')) {
            if (dfs(l + i, x + 3)) {
                return f[l][x] = 1;
            }
        }
    }
    return 0;
}
int main() {
    int t, k;
    scanf("%d", &t);
    while (t--) {
        memset(f, -1, sizeof(f));
        scanf("%d%d", &n, &k);
        int p = 0;
        for (int i = 0; i < 3; ++i) {
            scanf("%s", s[i]);
            if (s[i][0] == 's') {
                p = i;
            }
        }
        puts(dfs(p, 0) ? "YES" : "NO");
    }
    return 0;
}