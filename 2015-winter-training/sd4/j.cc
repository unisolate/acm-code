#include <cstdio>
using namespace std;
char name[99], a[99], b[99];
int main() {
    int t, n, x, y, mod;
    long long s;
    scanf("%d", &t);
    while (t--) {
        int k, p = 0;
        scanf("%d%lld%d%d%d", &n, &s, &x, &y, &mod);
        for (int i = 0; i < n; ++i) {
            scanf("%s%s%d%s", name, a, &k, b);
            while (p + k > s) {
                printf("%lld pages for %s\n", s - p, name);
                p = 0;
                s = (s * x + y) % mod;
            }
            printf("%d pages for %s\n", k, name);
            p += k;
        }
        if (t) puts("");
    }
    return 0;
}