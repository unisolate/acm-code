#include <bits/stdc++.h>
using namespace std;
int p[11111];
int main()
{
    int n, q, t, cas = 0;
    while (scanf("%d%d", &n, &q) && n + q)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        sort(p, p + n);
        printf("CASE# %d:\n", ++cas);
        while (q--)
        {
            scanf("%d", &t);
            int l = 0, r = n - 1, m;
            bool f = true;
            while (l <= r)
            {
                m = l + r >> 1;
                if (p[m] == t)
                {
                    while (p[m] == t) --m;
                    printf("%d found at %d\n", t, m + 2);
                    f = false;
                    break;
                }
                if (p[m] < t)
                    l = m + 1;
                else r = m - 1;
            }
            if (f) printf("%d not found\n", t);
        }
    }
    return 0;
}