#include <cstdio>
#define MX 9999
using namespace std;
int a[MX], m[MX];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++m[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        while (m[i] > 1) {
            for (int j = i + 1; j < MX; ++j) {
                if (m[j] == 0) {
                    m[j] = 1;
                    ans += (j - i);
                    --m[i];
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}