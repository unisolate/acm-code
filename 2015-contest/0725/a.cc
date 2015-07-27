#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 1024
using namespace std;
typedef long long ll;
struct P {
    ll a, b, c;
    int d;
} p[MX];
int cmp(P x, P y) {
    if (x.a == y.a) {
        if (x.b == y.b) {
            return x.c > y.c;
        }
        return x.b > y.b;
    }
    return x.a > y.a;
}
int n;
ll dp[MX];
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld%lld%d", &p[i].a, &p[i].b, &p[i].c, &p[i].d);
            dp[i] = p[i].c;
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; ++i) {
            if (p[i].d == 0) {
                for (int j = 0; j < n; ++j) {
                    if (i == j)continue;
                    if (p[i].a <= p[j].a && p[i].b <= p[j].b) {
                        dp[i] = max(dp[i], dp[j] + p[i].c);
                    }
                }
            } else if (p[i].d == 1) {
                for (int j = 0; j < n; ++j) {
                    if (i == j)continue;
                    ll x = p[i].a * p[i].b + p[i].a * p[i].c + p[i].b * p[i].c;
                    ll y = p[j].a * p[j].b + p[j].a * p[j].c + p[j].b * p[j].c;
                    if (p[i].a <= p[j].a && p[i].b <= p[j].b && x < y) {
                        dp[i] = max(dp[i], dp[j] + p[i].c);
                    }
                }
            } else if (p[i].d == 2) {
                for (int j = 0; j < n; ++j) {
                    if (i == j)continue;
                    if (p[i].a < p[j].a && p[i].b < p[j].b) {
                        dp[i] = max(dp[i], dp[j] + p[i].c);
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dp[i]);
        printf("%lld\n", ans);
    }
    return 0;
}