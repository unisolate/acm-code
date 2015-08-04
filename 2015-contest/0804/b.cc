#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    int t;
    ll n, m, z, l, x, a;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &n, &m, &z, &l);
        a = x = 0;
        for (int i = 1; i < n; ++i) {
            x = (x * m + z) % l;
            a = a ^ (2 * x);
        }
        printf("%lld\n", a);
    }
    return 0;
}