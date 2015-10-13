#include <cstdio>
#include <algorithm>
#include <cstring>
#define MX 100010
using namespace std;
int a[2][MX], b[MX], c[MX];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            c[i] += a[0][j];
        }
        c[i] += b[i];
        for (int j = i; j < n; ++j) {
            c[i] += a[1][j];
        }
    }
    sort(c, c + n);
    ans = c[0] + c[1];
    printf("%d\n", ans);
    return 0;
}