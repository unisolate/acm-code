#include <cstdio>
int p[99][99];
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        p[i][1] = p[1][i] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            p[i][j] = p[i - 1][j] + p[i][j - 1];
    printf("%d", p[n][n]);
    return 0;
}