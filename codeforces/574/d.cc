#include <cstdio>
#include <algorithm>
#define MX 100010
using namespace std;
int h[MX], v[MX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", h + i);
        v[i] = h[i];
    }
    int ans = 0, k, l = 1, r = n, L, R;
    while (1) {
        ++ans;
        bool f = true;
        L = -1;
        if (ans % 2) {
            for (int i = l; i <= r; ++i) {
                if (h[i] > 0) {
                    if (L == -1)
                        L = i;
                    R = i;
                    k = min(h[i - 1], h[i + 1]);
                    if (h[i] > k) {
                        v[i] = k;
                    } else {
                        v[i] = h[i] - 1;
                    }
                    if (v[i] > 0)
                        f = false;
                } else
                    v[i] = 0;
            }
        } else {
            for (int i = l; i <= r; ++i) {
                if (v[i] > 0) {
                    if (L == -1)
                        L = i;
                    R = i;
                    k = min(v[i - 1], v[i + 1]);
                    if (v[i] > k) {
                        h[i] = k;
                    } else {
                        h[i] = v[i] - 1;
                    }
                    if (h[i] > 0)
                        f = false;
                } else
                    h[i] = 0;
            }
        }
        if (f) {
            break;
        }
        l = L, r = R;
        // if (ans % 2) {
        //     for (int i = 1; i <= n; ++i)
        //         printf("%d ", v[i]);
        //     puts("");
        // } else {
        //     for (int i = 1; i <= n; ++i)
        //         printf("%d ", h[i]);
        //     puts("");
        // }
    }
    printf("%d\n", ans);
    return 0;
}