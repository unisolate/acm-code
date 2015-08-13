#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}
int main() {
    int t;
    ll x, y, z;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld:%lld:%lld", &x, &y, &z);
        if (x >= 12) x -= 12;
        // double aa = 360 * (double)(x * 3600 + y * 60 + z) / (43200);
        // double ab = 360 * (double)(y * 60 + z) / (3600);
        // double ac = 360 * (double)(z) / 60;
        bool f = false;
        ll a = 360 * ((x * 3600 + y * 60 + z) * 3600 - (y * 60 + z) * 43200);
        // if (aa > ab)
        //     a = (x * 3600 + y * 60 + z) * 3600 - (y * 60 + z) * 43200;
        // else a = (y * 60 + z) * 43200 - (x * 3600 + y * 60 + z) * 3600;
        if (a < 0) {
            // a += 180 * 86400 * 3600LL;
            a = -a;
            // f = true;
        }
        // printf("%lld\n", a);
        if (a > 180 * 43200 * 3600LL) {
            a = 43200 * 3600LL * 360 - a;
        }
        ll b = gcd(a, 43200 * 3600LL);
        if (b == 43200 * 3600LL) {
            printf("%lld ", a / b);
        } else {
            printf("%lld/%lld ", a / b, 43200 * 3600LL / b);
        }

        a = 360 * ((x * 3600 + y * 60 + z) * 60 - (z) * 43200);
        if (a < 0) a = -a;
        if (a > 180 * 60 * 43200LL) {
            a = 360 * 43200 * 60 - a;
        }
        b = gcd(a, 43200 * 60LL);
        if (b == 43200 * 60LL) {
            printf("%lld ", a / b);
        } else {
            printf("%lld/%lld ", a / b, 43200 * 60LL / b);
        }

        a = 360 * ((y * 60 + z) * 60 - (z) * 3600);
        if (a < 0) a = -a;
        if (a > 180 * 60 * 3600LL) {
            a = 360 * 3600 * 60 - a;
        }
        b = gcd(a, 3600 * 60LL);
        if (b == 3600 * 60LL) {
            printf("%lld \n", a / b);
        } else {
            printf("%lld/%lld \n", a / b, 3600 * 60LL / b);
        }
    }
    return 0;
}