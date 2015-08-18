#include <cstdio>
using namespace std;
int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%7d ", i * i + 100000 * i + j * j - 100000 * j + i * j);
            }
            puts("");
        }
    }
    return 0;
}