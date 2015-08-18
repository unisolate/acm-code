#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
ll a[100010];
vector<pair<bool, pair<int, ll> > > v;
int main() {
    int n;
    ll x, y;
    while (~scanf("%d%lld%lld", &n, &x, &y)) {
        v.clear();
        ll ans = n;
        for (int i = 0; i < n; ++i)
            scanf("%lld", a + i);
        if (x == y) {
            ll b = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (a[i + 1] - a[i] == x) {
                    ++b;
                } else {
                    if (b)
                        v.push_back(make_pair(true, make_pair(i, b)));
                    b = 0;
                }
            }
            if (b)
                v.push_back(make_pair(true, make_pair(n - 1, b)));
            for (int i = 0; i < v.size(); ++i) {
                ans += v[i].second.second * (v[i].second.second + 1) / 2;
            }
        } else {
            ll b = 0, c = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (a[i + 1] - a[i] == x) {
                    ++b;
                } else {
                    if (b)
                        v.push_back(make_pair(true, make_pair(i, b)));
                    b = 0;
                }
                if (a[i + 1] - a[i] == y) {
                    ++c;
                } else {
                    if (c)
                        v.push_back(make_pair(false, make_pair(i, c)));
                    c = 0;
                }
            }
            if (b)
                v.push_back(make_pair(true, make_pair(n - 1, b)));
            if (c)
                v.push_back(make_pair(false, make_pair(n - 1, c)));
            for (int i = 0; i < v.size(); ++i) {
                // printf("%lld %lld\n", v[i].first, v[i].second);
                ans += v[i].second.second * (v[i].second.second + 1) / 2;
                if (i > 0 && v[i].first == false && v[i - 1].first == true) {
                    if (v[i].second.first - v[i].second.second == v[i - 1].second.first) {
                        ans += v[i].second.second * v[i - 1].second.second;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}