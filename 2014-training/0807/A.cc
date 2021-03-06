#include <bits/stdc++.h>
#define MX 222222
using namespace std;
int a[MX], ans[MX];
map<int, int> mp;
void add(int p, int x)
{
    mp[p] += x;
    if (!mp[p])
        mp.erase(p);
}
int main()
{
    int n, m, p, b, q = 0;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b), ++mp[b];
    for (int i = 0; i < p; ++i)
    {
        int j = i, k = 0;
        for (; j < n; j += p, ++k)
        {
            add(a[j], -1);
            if (k >= m)
                add(a[j - p * m], 1);
            if (mp.empty())
                ans[q++] = j - p * m + p + 1;
        }
        for (j -= p, k = 0; j >= 0 && k < m; j -= p, ++k)
            add(a[j], 1);
    }
    sort(ans, ans + q);
    printf("%d\n", q);
    for (int i = 0; i < q; ++i)
        printf("%d ", ans[i]);
    return 0;
}