#include <cstdio>
#define MX 10001
using namespace std;
int s[MX], p[MX];
int main() {
    int t, cas = 0, n, q, a, b, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", s + i);
            p[i] = s[i];
        }
        int k = 1;
        bool f = false;
        while (k < n) {
            for (int i = 0; i + k < n; i += k * 2) {
                if (f) {
                    s[i] -= s[i + k];
                } else {
                    s[i] += s[i + k];
                }
            }
            f = !f;
            k *= 2;
        }
        printf("%d ", s[0]);
        x = s[0];
        if (cas % 2) ++x;
        if (x % 2) {
            puts("Rusa");
        } else puts("Sanches");
        while (q--) {
            scanf("%d%d", &a, &b);
            int cnt = 0;
            x = (a - 1) / 2;
            if (x % 2) ++cnt;
            while (x) {
                x = x / 4;
                if (x % 2)
                    ++cnt;
            }
            if (cnt % 2)
                s[0] -= b - p[a - 1];
            else s[0] += b - p[a - 1];
            p[a - 1] = b;
            printf("%d ", s[0]);
            x = s[0];
            if (cas % 2) ++x;
            if (x % 2) {
                puts("Rusa");
            } else puts("Sanches");
        }
        ++cas;
    }
    return 0;
}