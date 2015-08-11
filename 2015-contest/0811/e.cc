#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    int n, t, cas = 0;
    while (scanf("%d%d", &n, &t) && n != -1 && t != -1) {
        ll x = 0, y = 0, s = 0, c = 0;
        for (int i = 0; i <= t; ++i) {
            ll k = s ? s : n, a = 0, b = 0;
            int j = 0;
            while (k) {
                s += k % 10;
                if (j % 2) {
                    a += k % 10;
                } else {
                    b += k % 10;
                }
                ++j;
                k /= 10;
            }
            if ((c + j) % 2) x += b, y += a;
            else x += a, y += b;
            c += j;
            // printf("%lld %lld\n", x, y);
        }
        printf("Case #%d: ", ++cas);
        puts((x - y) % 11 ? "No" : "Yes");
    }
    return 0;
}