#include <cstdio>
#include <map>
#include <queue>
using namespace std;
typedef unsigned long long ull;
int n, s, a[8];
queue<pair<ull, int> > q;
map<ull, bool> mp;
pair<ull, int> p;
inline int get(ull v, int x, int y) {
    return 1 & (v >> (x * n + n - y - 1));
}
inline ull rev(ull v, int x, int y) {
    return v ^ (1ULL << (x * n + n - y - 1));
}
inline bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
ull flip(ull v, int x, int y) {
    v = rev(v, x, y);
    if (ok(x - 1, y)) v = rev(v, x - 1, y);
    if (ok(x + 1, y)) v = rev(v, x + 1, y);
    if (ok(x, y - 1)) v = rev(v, x, y - 1);
    if (ok(x, y + 1)) v = rev(v, x, y + 1);
    return v;
}
int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        mp.clear();
        while (!q.empty()) q.pop();
        scanf("%d", &n);
        ull v = 0ULL, t;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            v |= (a[i] << (i * n));
        }
        q.push(make_pair(v, 0));
        mp[v] = true;
        int ans = -1;
        while (!q.empty()) {
            p = q.front();
            v = p.first;
            s = p.second;
            q.pop();
            if (v == 0ULL) {
                ans = s;
                break;
            }
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    if (get(v, i, j)) {
                        // printf("#%d %d\n", i, j);
                        t = flip(v, i, j);
                        if (mp[t] == false) {
                            q.push(make_pair(t, s + 1));
                            mp[t] = true;
                        }
                    }
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}