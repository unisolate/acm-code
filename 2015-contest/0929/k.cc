#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 100010
using namespace std;
int p[MX], f[MX];
int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        memset(f, 0, sizeof(f));
        scanf("%d%d", &n, &k);
        bool zero = false;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            f[p[i]]++;
        }
        sort(p, p + n);
        if (p[0] == 0) {
            if (k == 0) {
                printf("%d %d\n", p[0], p[1]);
                zero = true;
            }
        }
        if (zero) {
            continue;
        }
        bool a = false;
        for (int i = 0; i < n; ++i) {
            if (p[i] == 0) {
                continue;
            }
            if (k < p[i]) {
                continue;
            }
            if (k % p[i] == 0 && f[k / p[i]]) {
                if (p[i] == k / p[i] && f[p[i]] < 2) {
                    continue;
                }
                printf("%d %d\n", p[i], k / p[i]);
                a = true;
                break;
            }
        }
        if (!a) {
            puts("-1");
        }
    }
    return 0;
}