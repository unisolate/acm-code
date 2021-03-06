#include <cstdio>
#include <algorithm>
#define MY 102400
#define MX 10240000
using namespace std;
int a[MY], b[MY], p[MX], x[MX], y[MX];
void e() {
    for (int i = 2; i < MX; ++i)
        if (!p[i])
            for (int j = i; j < MX; j += i)
                p[j] = i;
}
void r(int *c, int n, int *z) {
    for (int i = 0; i < n; ++i)
        for (int j = c[i]; j > 1; j /= p[j])
            ++z[p[j]];
}
void o(int *c, int n, int *z) {
    for (int i = 0; i < n; ++i) {
        int v = 1;
        for (int j = c[i]; j > 1; j /= p[j])
            z[p[j]] ? z[p[j]]-- : v *= p[j];
        printf("%d ", v);
    }
    puts("");
}
int main() {
    e();
    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    r(a, n, x), r(b, m, y);
    printf("%d %d\n", n, m);
    o(a, n, y), o(b, m, x);
    return 0;
}