#include <cstdio>
using namespace std;
int x[102400], y[102400], a[102400], p[102400];
int k;
int f(int x) {
    return x == p[x] ? x : (p[x] = f(p[x]));
}
void uni(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y)
        return;
    --k;
    p[x] = y;
}
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", x + i, y + i);
        }
        k = n;
        for (int i = m - 1; i >= 0; --i) {
            a[i] = k;
            uni(x[i], y[i]);
        }
        for (int i = 0; i < m; ++i)
            printf("%d\n", a[i]);
    }
    return 0;
}