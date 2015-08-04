#include <cstdio>
#define MX 33333
using namespace std;
int n, m, k, a, b, p[MX], q[MX];
int F(int x) {
    return x == p[x] ? x : (p[x] = F(p[x]));
}
void U(int x, int y) {
    x = F(x), y = F(y);
    if (x == y) return;
    p[x] = y;
    q[y] += q[x];
    q[x] = 0;
}
int main() {
    while (scanf("%d%d", &n, &m) && n + m) {
        for (int i = 0; i < n; ++i)
            p[i] = i, q[i] = 1;
        while (m--) {
            scanf("%d%d", &k, &a);
            for (int i = 1; i < k; ++i) {
                scanf("%d", &b);
                U(a, b);
            }
        }
        printf("%d\n", q[F(0)]);
    }
    return 0;
}