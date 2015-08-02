#include <cstdio>
#define MX 10001
using namespace std;
int cas, n, x, s[MX], p[MX];
void run() {
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
}
int main() {
    int t, q, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", s + i);
            p[i] = s[i];
        }
        run();
        while (q--) {
            scanf("%d%d", &a, &b);
            p[a - 1] = b;
            for (int i = 0; i < n; ++i)
                s[i] = p[i];
            run();
        }
        ++cas;
    }
    return 0;
}