#include <cstdio>
using namespace std;
int f[1024][1024];
int main() {
    int n, m, k, x, y, p = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &x, &y);
        ++x, ++y;
        f[x][y] = 1;
        if (p == 0) {
            if (f[x][y + 1] + f[x + 1][y + 1] + f[x + 1][y] == 3)
                p = i + 1;
            if (f[x][y + 1] + f[x - 1][y + 1] + f[x - 1][y] == 3)
                p = i + 1;
            if (f[x][y - 1] + f[x - 1][y - 1] + f[x - 1][y] == 3)
                p = i + 1;
            if (f[x][y - 1] + f[x + 1][y - 1] + f[x + 1][y] == 3)
                p = i + 1;
        }
    }
    printf("%d", p);
    return 0;
}