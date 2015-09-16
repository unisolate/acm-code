#include <cstdio>
#include <algorithm>
#define MX 222222
using namespace std;
typedef long long ll;
int n, k, p[64];
ll x, a[MX], e[64];
bool cmp(ll u, ll v) {
    int c = 0, d = 0;
    ll r = u, s = v;
    while (u) {
        ++c;
        u >>= 1;
    }
    while (v) {
        ++d;
        v >>= 1;
    }
    c = max(c, d);
    while (c >= 0) {
        if ((r >> c & 1) == (s >> c & 1)) {
            --c;
        } else {
            return (r >> c & 1) > (s >> c & 1);
        }
    }
    return 0;
}
int main() {
    scanf("%d%d%lld", &n, &k, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < k; ++i) {
        a[0] *= x;
    }
    for (int i = 0; i < n; ++i) {
        ll t = a[i];
        int c = 0;
        while (t) {
            p[c++] += (t & 1);
            t >>= 1;
        }
    }
    ll ans = 0, q = 1;
    for (int i = 0; i < 64; ++i) {
        if (p[i]) {
            ans += q;
        }
        q *= 2;
    }
    printf("%lld\n", ans);
    return 0;
}