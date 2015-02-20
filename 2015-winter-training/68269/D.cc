#include <cstdio>
#include <queue>
using namespace std;
char s[9][9];
int u[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int v[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
bool c(int n) {
    return (n >= 0 && n < 8);
}
bool bfs() {
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(7, 0)));
    while (!q.empty()) {
        int t = q.front().first, x = q.front().second.first,
            y = q.front().second.second;
        if (x == 0 && y == 7) return true;
        q.pop();
        if (x - t < 0 || (c(x - t) && s[x - t][y] != 'S')) {
            for (int i = 0; i < 9; ++i) {
                if (c(x + u[i]) && c(y + v[i])) {
                    if (x + u[i] - t < 0 || (x + u[i] - t >= 0
                                             && s[x + u[i] - t][y + v[i]] != 'S')) {
                        q.push(make_pair(t + 1, make_pair(x + u[i], y + v[i])));
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    for (int i = 0; i < 8; ++i)
        scanf("%s", s[i]);
    if (bfs()) puts("WIN");
    else puts("LOSE");
    return 0;
}