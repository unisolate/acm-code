#include <cstdio>
#include <cstring>
#include <queue>
#define MX 102400
using namespace std;
int n, k, t, f[MX], p[MX];
void bfs() {
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t == k) {
            printf("%d\n", p[t]);
            return;
        }
        if (t + 1 < MX && !f[t + 1]) {
            f[t + 1] = 1;
            p[t + 1] = p[t] + 1;
            q.push(t + 1);
        }
        if (t - 1 >= 0 && !f[t - 1]) {
            f[t - 1] = 1;
            p[t - 1] = p[t] + 1;
            q.push(t - 1);
        }
        if (t * 2 < MX && !f[t * 2]) {
            f[t * 2] = 1;
            p[t * 2] = p[t] + 1;
            q.push(t * 2);
        }
    }
}
int main() {
    while (~scanf("%d%d", &n, &k)) {
        if (n < k) {
            memset(f, 0, sizeof(f));
            bfs();
        }
        else printf("%d\n", n - k);
    }
    return 0;
}