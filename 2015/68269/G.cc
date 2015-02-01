#include <cstdio>
#include <algorithm>
using namespace std;
struct P {
    int x, y, d;
} p[111];
int c1(P a, P b) {
    return a.x < b.x;
}
int c2(P a, P b) {
    return a.y < b.y;
}
int c[111], s;
int f(int x) {
    return x == c[x] ? x : (c[x] = f(c[x]));
}
void uni(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return;
    --s;
    c[x] = y;
}
int main() {
    int n;
    scanf("%d", &n);
    s = n;
    for (int i = 0; i < n; ++i) {
        c[i] = i;
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].d = i;
    }
    sort(p, p + n, c1);
    for (int i = 1; i < n; ++i) {
        if (p[i].x == p[i - 1].x)
            uni(p[i - 1].d, p[i].d);
    }
    sort(p, p + n, c2);
    for (int i = 1; i < n; ++i) {
        if (p[i].y == p[i - 1].y)
            uni(p[i - 1].d, p[i].d);
    }
    printf("%d", s - 1);
    return 0;
}