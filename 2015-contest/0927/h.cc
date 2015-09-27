#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int p[64], q[64];
int main() {
    int t, d, x, y, c = 0;
    scanf("%d", &t);
    while (t--) {
        memset(q, 0, sizeof(q));
        scanf("%d%d%d", &d, &x, &y);
        int k = 0, h = __builtin_popcount(d);
        while (d) {
            q[k++] = d & 1;
            d >>= 1;
        }
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 64; ++j) {
                p[j] = q[j];
            }
            int v = h;
            if (p[i] == 0) {
                p[i] = 1;
                ++v;
                for (int j = i - 1; j >= 0; --j) {
                    if (p[j] == 1) {
                        p[j] = 0;
                        --v;
                    }
                }
                for (int j = 0; j < i; ++j) {
                    if (v >= x && v <= y) {
                        break;
                    }
                    p[j] = 1;
                    ++v;
                }
                if (v >= x && v <= y) {
                    break;
                }
            }
        }
        ll a = 0, u = 1;
        for (int i = 0; i < 64; ++i) {
            a += p[i] * u;
            u *= 2;
        }
        printf("Case #%d: %lld\n", ++c, a);
    }
    return 0;
}