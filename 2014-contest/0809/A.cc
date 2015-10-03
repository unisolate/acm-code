#include <bits/stdc++.h>
using namespace std;
int p[1111];
bool f[1111];
int main()
{
    int n, cnt = 0, s = 0, ans = -111111111;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; ++i)
        scanf("%d", &p[i]);
    sort(p, p + 2 * n - 1);
    if (n % 2)
    {
        for (int j = 0; j <= 2 * n - 1; ++j)
        {
            s = 0, cnt = j;
            for (int i = 0; i <= 2 * n - 1; ++i)
            {
                if (cnt)
                    s += (-p[i]), --cnt;
                else s += p[i];
            }
            ans = max(ans, s);
        }
    }
    else
    {
        for (int j = 0; j < 2 * n - 1; j += 2)
        {
            s = 0, cnt = j;
            for (int i = 0; i < 2 * n - 1; ++i)
            {
                if (cnt)
                    s += (-p[i]), --cnt;
                else s += p[i];
            }
            ans = max(ans, s);
        }
    }
    printf("%d", ans);
    return 0;
}