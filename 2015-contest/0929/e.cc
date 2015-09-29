#include <cstdio>
using namespace std;
int p[128];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", p + i);
            if (p[i] > m) {
                m = p[i];
            }
        }
        int a = 100 - m, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] + a >= 50) {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}