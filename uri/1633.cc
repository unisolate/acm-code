#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
struct P {
    ll x, y;
} p[102400];
int cx(P a, P b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}
class cmp {
  public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
        return a.second > b.second;
    }
};
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, cmp> q;
int main() {
    int n;
    while (~scanf("%d", &n)) {
        while (!q.empty()) q.pop();
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &p[i].x, &p[i].y);
        }
        sort(p, p + n, cx);
        ll ans = 0, t = 1;
        int k = 0;
        pair<ll, ll> v;
        for (int i = 0; i < n; ++i) {
            while (k < n && p[k].x <= t) {
                q.push(make_pair(p[k].x, p[k].y));
                ++k;
            }
            if (q.empty()) {
                q.push(make_pair(p[k].x, p[k].y));
                t = p[k].x;
                ++k;
            }
            v = q.top();
            q.pop();
            // printf("%lld %d %d\n", t, v.first, v.second);
            ans += t - v.first;
            t += v.second;
        }
        printf("%lld\n", ans);
    }
    return 0;
}