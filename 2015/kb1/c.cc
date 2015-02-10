#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int n, k, a, b;
typedef pair<int, int> pr;
void bfs() {
    queue<pr> q;
    q.push(make_pair(n, 0));
    while (!q.empty()) {
        pr t = q.front();
        // printf("#%d\n", t);
        q.pop();
        a = t.first, b = t.second;
        if (t.first == k) {
            printf("%d\n", b);
            return;
        }
        if (a > 0)
            q.push(make_pair(a - 1, b + 1));
        if (a < k) {
            q.push(make_pair(a + 1, b + 1));
            q.push(make_pair(a * 2, b + 1));
        }
    }
}
int main() {
    while (~scanf("%d%d", &n, &k)) {
        if (n < k) {
            bfs();
        }
        else printf("%d\n", n - k);
    }
    return 0;
}