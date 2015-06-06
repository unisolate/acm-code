#include <cstdio>
using namespace std;
char s[111][111];
int n, m;
int dfs(int xx, int yy, int x, int y, int v) {
    if (x == 0 && y == 0) {
        return v;
    }
    int ret = v;
    int i = x, j = y;
    bool a = false, b = false;
    for (; j >= yy; --j) {
        if (s[x][j] != s[x][y]) {
            a = true;
            break;
        }
    }
    for (; i >= xx; --i) {
        if (s[i][y] != s[x][y]) {
            b = true;
            break;
        }
    }
    if (a && b == false) {
        // ret++;
        ret += dfs(xx, j + 1, x, y, 0);
        ret += dfs(xx, yy, x, j, 1);
    } else if (a == false && b) {
        // ret++;
        ret += dfs(i + 1, yy, x, y, 0);
        ret += dfs(xx, yy, i, y, 1);
    } else if (a && b) {
        // ret += 3;
        ret += dfs(xx, yy, i, j, 1);
        ret += dfs(i + 1, yy, x, j, 1);
        ret += dfs(xx, j + 1, i, y, 1);
        ret += dfs(i + 1, j + 1, x, y, 0);
    } else if (a == false && b == false) {
        ret += dfs(xx, yy, x ? x - 1 : x, y ? y - 1 : y, 0);
    }
    return ret;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    printf("%d\n", dfs(0, 0, n - 1, m - 1, 1));
    return 0;
}