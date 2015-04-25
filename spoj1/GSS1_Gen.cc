#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("name.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int n, m;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i)
        printf("%d ", rand() % (4 * n) - 2 * n);
    putchar(10);
    m = n * (n + 1) / 2;
    printf("%d\n", m);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            printf("%d %d\n", i, j);
    return 0;
}