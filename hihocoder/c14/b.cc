#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define MX 100001
using namespace std;
int p[MX], q[MX];
vector<int> v[MX];
void dfs(int x, int y) {
    // printf("%d %d\n", x, y);
    p[x] = y;
    for (int i = 0; i < v[x].size(); ++i) {
        dfs(v[x][i], y + 1);
    }
}
int ddd(int x) {
    for (int i = 0; i < v[x].size(); ++i) {
        q[x] = max(q[x], ddd(v[x][i]));
    }
    return q[x] + 1;
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
    }
    int ans = 0;
    dfs(1, 0);
    ddd(1);
    for (int i = 1; i <= n; ++i) {
        // printf("%d\n", q[i]);
        int c = 0, d = 0, cc = 0;
        for (int j = 0; j < v[i].size(); ++j) {
            if (q[v[i][j]] > c) {
                c = q[v[i][j]];
                cc = j;
            }
        }
        for (int j = 0; j < v[i].size(); ++j) {
            if (j == cc)
                continue;
            if (q[v[i][j]] > d)
                d = q[v[i][j]];
        }
        // printf("%d %d %d\n", p[i], c, d);
        if (v[i].size() > 1)
            ans = max(ans, p[i] + c + d + 2);
        else if (v[i].size() == 1)
            ans = max(ans, p[i] + c + 1);
        else
            ans = max(ans, p[i]);
    }
    printf("%d\n", ans);
    return 0;
}