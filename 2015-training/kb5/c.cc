#include <cstdio>
using namespace std;
int n, m, a, b, p[1024];
int F(int x) {
    return x == p[x] ? x : (p[x] = F(p[x]));
}
void U(int x, int y) {
    x = F(x), y = F(y);
    if (x == y) return;
    --n;
    p[x] = y;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            p[i] = i;
        while (m--) {
            scanf("%d%d", &a, &b);
            U(a, b);
        }
        printf("%d\n", n);
    }
    return 0;
}