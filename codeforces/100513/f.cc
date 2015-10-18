#include <cstdio>
#include <algorithm>

int a[200001];
int d[3][200001];

int main() {
    int i, j, n, m;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    n = 200000;
    for (i = 1; i <= n; i++)
        a[i] += a[i - 1];
    m = std::min(100000, m);
    for (i = 1; i <= 2; i++)
        for (j = m * i; j <= n; j++)
            d[i][j] = std::max(d[i][j - 1], d[i - 1][j - m] + a[j] - a[j - m]);
    printf("%d", d[2][n]);
}