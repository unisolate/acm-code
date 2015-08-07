#include <cstdio>
#include <algorithm>
#include <queue>
#define MX 100010
using namespace std;
struct s {
    int l, r, i;
} p[MX];
int ans[MX];
bool v[MX];
bool operator<(const s &a, const s &b) {
    return a.r > b.r;
}
bool cmp(s a, s b) {
    if (a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}
priority_queue<s> q;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        while (!q.empty()) q.pop();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i].l);
            p[i].i = i + 1;
            v[i + 1] = true;
        }
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i].r);
        sort(p, p + n, cmp);
        int k = 0, x = 0;
        while (k < n) {
            while (x < n && p[x].l <= k) {
                q.push(p[x]);
                ++x;
            }
            while (!q.empty() && k > q.top().r)
                q.pop();
            if (q.empty()) {
                break;
            }
            // printf("%d ", q.top().i);
            ans[k++] = q.top().i;
            v[q.top().i] = false;
            q.pop();
        }
        printf("%d\n", k);
        for (int i = 1; i <= n; ++i) {
            if (v[i])
                printf("%d%c", i, (k == 0 && i == n) ? '\n' : ' ');
        }
        for (int i = 0; i < k; ++i) {
            printf("%d%c", ans[i], (i == k - 1) ? '\n' : ' ');
        }
    }
    return 0;
}