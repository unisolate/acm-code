#include <cstdio>
int main()
{
    int t, n, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int sum = 0, max = -1001, p, q, num;
        for (int i = 1, j = 1; j <= n; ++j)
        {
            scanf("%d", &num);
            sum += num;
            if (sum > max)
                max = sum, p = i, q = j;
            if (sum < 0)
                sum = 0, i = j + 1;
        }
        if (cas)
        	putchar(10);
        printf("Case %d:\n%d %d %d\n", ++cas, max, p, q);
    }
    return 0;
}