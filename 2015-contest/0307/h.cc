#include <cstdio>
#include <cmath>
using namespace std;
int t, n, x, y;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int a = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            int d = x * x + y * y;
            for (int i = 1; i <= 10; ++i)
                if (20 * i * 20 * i >= d) {
                    a += 11 - i;
                    break;
                }
        }
        printf("%d\n", a);
    }
    return 0;
}