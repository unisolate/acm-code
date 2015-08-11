#include <cstdio>
using namespace std;
typedef long long ll;
ll x[100010];
bool m[100010];
int a[100010], b[100010];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll s = 0, v;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", x + i);
            s += x[i];
            m[i] = false;
        }
        bool f = (s % n == 0);
        v = s / n;
        int c = 0;
        if (f) {
            for (int i = 0; i < n; ++i) {
                if (x[i] - v < -2 || x[i] - v > 2) {
                    f = false;
                    break;
                }
                if (x[i] - v == -2) {
                    --x[i - 1], --x[i + 1];
                    m[i - 1] = m[i] = false;
                    x[i] += 2;
                }
                if (x[i] - v == 2) {
                    ++x[i - 1], ++x[i + 1];
                    m[i - 1] = m[i] = false;
                    x[i] -= 2;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (x[i] - v < -1 || x[i] - v > 1) {
                    f = false;
                    break;
                }
            }
        }
        if (f) {
            for (int i = 0; i < n; ++i) {
                if (x[i] != v) {
                    f = false;
                    break;
                }

            }
        }
        if (f) {
            puts("YES");
            printf("%d\n", c);
            for (int i = 0; i < c; ++i) {
                printf("%d %d\n", a[i] + 1, b[i] + 1);
            }
        } else
            puts("NO");
    }
    return 0;
}