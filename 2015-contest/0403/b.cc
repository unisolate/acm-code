#include <cstdio>
#include <map>
#define MX 102400
#define MOD 142857
using namespace std;

int n, m;
int s[MX], q[MX], k[MX], p[MX][3], a[MX];
bool f[MX];
// map<int, int> mp;

void dfs(int x) {
    ++a[x];
    for (int i = 0; i < n; ++i) {
        if (s[i] == x)
            for (int j = 0; j < k[i]; ++j)
                dfs(p[i][j]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", &q[i]);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &s[i], &k[i]);
            // mp[s[i]] = i;
            for (int j = 0; j < k[i]; ++j)
                scanf("%d", &p[i][j]);
        }
        for (int i = 0; i < m; ++i) {
            // ++a[q[i]];
            dfs(q[i]);
        }
        if (n > 0)
            printf("%d", a[s[0]] % MOD);
        for (int i = 1; i < n; ++i)
            printf(" %d", a[s[i]] % MOD);
        printf("\n");
    }
    return 0;
}