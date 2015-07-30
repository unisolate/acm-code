#include <cstdio>
#include <cstring>
#define MX 1000001
using namespace std;
bool f[MX];
int n, m;
void dfs(int p, int l) {
    f[p] = true;
    if (p + l <= n) dfs(p + l, l + 2);
    if (p - l >= 1) dfs(p - l, l + 2);
}
int main() {
    while (scanf("%d%d", &n, &m) && n + m) {
        memset(f, false, sizeof(f));
        if (n < 49) {
            dfs(1, 3);
            if (f[m]) {
                puts("Let me try!");
            } else {
                puts("Don't make fun of me!");
            }
        } else {
            puts("Let me try!");
        }
        // dfs(1, 3);
        // for (int i = 1; i <= n; ++i) {
        //     if (!f[i])
        //         printf("%d ", i);
        // }
    }
    return 0;
}