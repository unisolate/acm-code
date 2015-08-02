#include <cstdio>
#include <map>
#define MX 2147483647
using namespace std;
typedef long long ll;
map<int, int> m;
ll p(ll x, int y) {
    ll r = x;
    for (int i = 1; i < y; ++i)
        r *= x;
    return r;
}
int main() {
    ll t;
    for (ll i = 1; i < 65536; ++i) {
        for (ll j = i + 1; j < 65536; ++j) {
            for (int k = 2; k < 32; ++k) {
                t = p(i, k) + p(j, k) + i * j * k;
                if (t > MX)
                    break;
                ++m[t];
            }
        }
    }
    int k;
    while (scanf("%d", &k) && k) {
        printf("%d\n", m[k]);
    }
    return 0;
}