#include <bits/stdc++.h>
int num[100001], lis[100001];
int main()
{
    int n, i, len;
    while (~scanf("%d", &n))
    {
        len = 1;
        scanf("%d", &num[1]);
        lis[1] = num[1];
        for (i = 2; i <= n; i++)
        {
            scanf("%d", &num[i]);
            if (num[i] > lis[len])
                lis[++len] = num[i];
            else
            {
                int m, x = 1, y = len;
                while (x < y)
                {
                    m = (x + y) >> 1;
                    if (lis[m] >= num[i])
                        y = m;
                    else x = m + 1;
                }
                lis[x] = num[i];
            }
        }
        printf("%d\n", len);
        for (int i = 0; i <= len; ++i)
            printf("%d ", lis[i]);
    }
    return 0;
}