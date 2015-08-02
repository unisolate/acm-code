#include <cstdio>
#include <map>
using namespace std;
int a[10];
int main() {
    int x, y, u, v, k;
    u = 1;
    a[0] = 0;
    for (int i = 1; i < 10; ++i, u *= 10) {
        a[i] = 8 * a[i - 1] + 2 * u;
        // printf("%d\n",a[i]);
    }
    while (scanf("%d", &x) && x) {
        y = x, u = 1, v = 0, k = 0;
        while (y) {
            for (int i = 0; i < y % 10; ++i) {
                if (i == 3 || i == 8) {
                    v += u;
                } else {
                    v += a[k];
                }
            }
            y /= 10;
            u *= 10;
            ++k;
        }
        printf("%d: %d\n", x, x - v);
    }
    return 0;
}