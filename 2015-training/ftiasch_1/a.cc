#include <cstdio>
using namespace std;
int x, y;
unsigned int m[10010][42];
int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &x);
            m[x][i / 32] |= (1 << (i % 32));
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &x, &y);
        bool f = true;
        for (int i = 0; i < 42; ++i)
            if (m[x][i] & m[y][i]) {
                puts("Yes");
                f = false;
                break;
            }
        if (f) puts("No");
    }
    return 0;
}