#include <bits/stdc++.h>
#define MX 100010
using namespace std;
int p[MX], l[MX], r[MX], val[MX], cnt[MX], num[MX], d[MX][20];
void init(int n)
{
    for (int i = 0; i < n; ++i)
        d[i][0] = cnt[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}
int rmq(int x, int y)
{
    if (x > y)
        return 0;
    int k = 0;
    while ((1 << (k + 1)) <= y - x + 1)
        ++k;
    return max(d[x][k], d[y - (1 << k) + 1][k]);
}
int main()
{
    int n, q;
    while (~scanf("%d", &n) && n)
    {
        scanf("%d", &q);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        p[n + 1] = -MX;
        int k = 0;
        cnt[k] = 1, val[k] = p[1], l[1] = 1;
        for (int i = 2; i <= n + 1; ++i)
        {
            if (p[i] == p[i - 1])
                ++cnt[k], l[i] = l[i - 1], num[i] = k;
            else
            {
                for (int j = l[i - 1]; j < i; ++j)
                    r[j] = i - 1;
                ++k, num[i] = k, l[i] = i, cnt[k] = 1, val[k] = p[i];
            }
        }
        // for (int i = 1; i <= n; ++i)
        //     printf("#%d %d %d\n", l[i], r[i], num[i]);
        // for (int i = 0; i < k; ++i)
        //     printf("##%d %d\n", cnt[i], val[i]);
        int x, y, ans;
        init(k);
        while (q--)
        {
            scanf("%d%d", &x, &y);
            if (num[x] == num[y])
                ans = y - x + 1;
            else ans = max(max(r[x] - x + 1, y - l[y] + 1), rmq(num[x] + 1, num[y] - 1));
            printf("%d\n", ans);
        }
    }
    return 0;
}