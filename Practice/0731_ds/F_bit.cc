#include <bits/stdc++.h>
#define MX 100010
using namespace std;
int p[MX], l[MX], r[MX], val[MX], cnt[MX], num[MX], idx[MX];
void init(int n)
{
    for (int i = 1; i < n; ++i)
    {
        idx[i] = cnt[i];
        for (int j = 1; j < (i & -i); j <<= 1)
            idx[i] = max(idx[i], idx[i - j]);
    }
}
int query(int x, int y)
{
    if (x > y)return 0;
    int ans = cnt[y];
    while (1)
    {
        ans = max(ans, cnt[y]);
        if (x == y) break;
        for (y -= 1; y - x >= (y & -y); y -= (y & -y))
            ans = max(ans, idx[y]);
    }
    return ans;
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
        int k = 1;
        cnt[k] = 1, val[k] = p[1], l[1] = 1, num[1] = k;
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
        int x, y, ans;
        init(k);
        while (q--)
        {
            scanf("%d%d", &x, &y);
            if (num[x] == num[y])
                ans = y - x + 1;
            else ans = max(max(r[x] - x + 1, y - l[y] + 1), query(num[x] + 1, num[y] - 1));
            printf("%d\n", ans);
        }
    }
    return 0;
}