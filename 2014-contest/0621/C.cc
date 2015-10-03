#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
using namespace std;
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 0; cas < t; ++cas)
    {
        int n, m, ans = 0;
        scanf("%d%d", &n, &m);
        int l[n];
        bool f[n];
        memset(f, false, sizeof(f));
        for (int i = 0; i < n; ++i)
            scanf("%d", &l[i]);
        sort(l, l + n, cmp);
        for (int i = 0; i < n; ++i)
        {
            if (f[i])
                continue;
            int k = m - l[i], j = n - 1;
            while (k >= l[j] && j > i)
                --j;
            ++j;
            for (; j < n; ++j)
                if (!f[j])
                    break;
            if (j != n)
                f[j] = true;
            f[i] = true;
            ++ans;
        }
        printf("%d\n", ans);
        if (cas != t - 1)
            printf("\n");
    }
    return 0;
}