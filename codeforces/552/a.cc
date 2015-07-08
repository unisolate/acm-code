#include <cstdio>
using namespace std;
int p[111][111];
int main() {
    int t, n, a, b, c, x, y;
    char s[99999];
    scanf("%d", &n);
    for (int k = 0; k < n; ++k) {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        for (int i = a; i <= x; ++i)
            for (int j = b; j <= y; ++j)
                ++p[i][j];
    }
    int ans = 0;
    for (int i = 0; i < 111; ++i)
        for (int j = 0; j < 111; ++j)
            ans += p[i][j];



    printf("%d\n", ans);
    return 0;
}