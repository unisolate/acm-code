#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 1024
using namespace std;
int c[MX][MX];
void u(int x, int y, int v) {
    ++x, ++y;
    for (; x < MX; x += (x & -x))
        for (int j = y; j < MX; j += (j & -j))
            c[x][j] += v;
}
int q(int x, int y) {
    ++x, ++y;
    int r = 0;
    for (; x > 0; x -= (x & -x))
        for (int j = y; j > 0; j -= (j & -j))
            r += c[x][j];
    return r;
}
int main() {
    int a, b, p, k, v, x, y, z, w;
    char o[9];
    while (scanf("%d%d%d", &a, &b, &p) && a + b + p) {
        memset(c, 0, sizeof(c));
        scanf("%d", &k);
        while (k--) {
            scanf("%s", o);
            if (o[0] == 'A') {
                scanf("%d%d%d", &v, &x, &y);
                u(x, y, v);
            } else {
                scanf("%d%d%d%d", &x, &y, &z, &w);
                if (x > z) swap(x, z);
                if (y > w) swap(y, w);
                printf("%d\n", (q(z, w) - q(x - 1, w) - q(z, y - 1) + q(x - 1, y - 1))*p);
            }
        }
        puts("");
    }
    return 0;
}