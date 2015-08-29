#include <cstdio>
using namespace std;
typedef long long ll;
u[7] = {0, 0, 1, 3, 6, 10, 15};
int main() {
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        ll ans = 0;
        int k = (a > 2 ? 2 : a) + (b > 2 ? 2 : b) + (c > 2 ? 2 : c);
        int v = (a ? 1 : 0) + (b ? 1 : 0) + (c ? 1 : 0);
        if (v == 1) {
            ans = a + b + c - 1;
        } else if (v == 2) {
            if (!a) {
                if (b == 1) {
                    ans = b + c;
                } else if (c == 1) {
                }
            } else if (!b) {
            } else {
            }
        } else {
            ans = u[k] + (ll)(a + b + c - k) * (k);
        }
        printf("%lld\n", ans);
    }
    return 0;
}