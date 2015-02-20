#include <cstdio>
#include <cstring>
using namespace std;
char p[9][9];
int c, n, k, q[9];
void dfs(int s, int v) {
    if (v == k) {
        ++c;
        return;
    }
    if (s == n) {
        return;
    }
    q[s] = n;
    dfs(s + 1, v);
    for (int i = 0, j; i < n; ++i)
        if (p[i][s] == '#') {
            for (j = 0; j < s; ++j)
                if (q[j] == i)
                    break;
            if (j < s)
                continue;
            q[s] = i;
            dfs(s + 1, v + 1);
        }
}
int main() {
    while (scanf("%d%d", &n, &k) && n > 0) {
        for (int i = 0; i < n; ++i)
            scanf("%s", p[i]);
        c = 0;
        memset(q, 0, sizeof(q));
        dfs(0, 0);
        printf("%d\n", c);
    }
    return 0;
}