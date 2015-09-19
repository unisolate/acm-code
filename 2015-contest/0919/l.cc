#include <cstdio>
#include <algorithm>
#define MX 5000050
using namespace std;
typedef long long ll;
struct T {
    int i;
    ll t;
} t[MX];
struct Q {
    int i;
    ll q;
} q[MX];
int ct(T a, T b) {
    return a.t < b.t;
}
int cq(Q a, Q b) {
    return a.q < b.q;
}
int main() {
    int p, n, cas = 0;
    ll a, b;
    scanf("%d", &p);
    while (p--) {
        scanf("%d%lld%lld", &n, &a, &b);
        for (int i = 0; i < n; ++i) {
            t[i].i = q[i].i = i;
            scanf("%lld", &t[i].t);
            q[i].q = t[i].t * t[i].t;
        }
        sort(t, t + n, ct);
        sort(q, q + n, cq);
        ll ans = 0;
        if (a < 0) {
            if (b < 0) {
                if (t[0].i == q[0].i) {
                    ans = max(a * q[1].q + b * t[0].t, a * q[0].q + b * t[1].t);
                } else {
                    ans = a * q[0].q + b * t[0].t;
                }
            } else {
                if (t[n - 1].i == q[0].i) {
                    ans = max(a * q[0].q + b * t[n - 2].t,
                              a * q[1].q + b * t[n - 1].t);
                } else {
                    ans = a * q[0].q + b * t[n - 1].t;
                }
            }
        } else {
            if (b < 0) {
                if (t[0].i == q[n - 1].i) {
                    ans = max(a * q[n - 1].q + b * t[1].t,
                              a * q[n - 2].q + b * t[0].t);
                } else {
                    ans = a * q[n - 1].q + b * t[0].t;
                }
            } else {
                if (t[n - 1].i == q[n - 1].i) {
                    ans = max(a * q[n - 1].q + b * t[n - 2].t,
                              a * q[n - 2].q + b * t[n - 1].t);
                } else {
                    ans = a * q[n - 1].q + b * t[n - 1].t;
                }
            }
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}