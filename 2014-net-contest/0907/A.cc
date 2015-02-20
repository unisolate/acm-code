#include <cstdio>
int p[111];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        for (int i = 1; i < n - 1; ++i)
            if (p[i - 1] < p[i] && p[i] > p[i + 1])
                ++ans;
        printf("%d\n", ans);
    }
    return 0;
}