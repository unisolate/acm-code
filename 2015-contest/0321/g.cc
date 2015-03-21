#include <cstdio>
#include <cstring>
#define MX 10240
using namespace std;
typedef long long ll;
ll a[MX], b[MX];
// ll c[MX];
// void U(int i, ll v) {
//     for (; i < MX; i += (i & -i))
//         c[i] += v;
// }
// ll Q(int i) {
//     ll r = 0;
//     for (; i > 0; i -= (i & -i))
//         r += c[i];
//     return r;
// }
int main() {
    int n;
    while (~scanf("%d", &n)) {
        // memset(c, 0, sizeof(c));
        ll s = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &a[i], &b[i]);
            s += a[i] - b[i];
            // U(i, a[i] - b[i]);
        }
        bool f = true;
        if (s % 2)
            f = false;
        else {
            for (int i = 1; i <= n; ++i) {
                if (s < 2 * (a[i] - b[i]))
                    f = false;
            }
        }
        if (f)
            puts("YES");
        else puts("NO");
    }
    return 0;
}