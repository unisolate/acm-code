#include <bits/stdc++.h>
using namespace std;
struct seg
{
    int l, r;
} p[300000];
int main()
{
    int L, R, k = 0;
    char s[10];
    while (~scanf("%s%d%d", s, &L, &R))
    {
        if (s[0] == '+')
        {
            p[++k].l = L, p[k].r = R;
            int ans = 0;
            for (int i = 1; i < k; ++i)
                if (p[i].l >= L && p[i].r <= R)
                    ++ans;
            printf("%d\n", ans);
        }
        if (s[0] == '-')
        {
            for (int i = 1; i <= k; ++i)
                if (p[i].l == L && p[i].r == R)
                {
                    for (int j = i; j < k; ++j)
                        p[j] = p[j + 1];
                    --k;
                    break;
                }
        }
    }
    return 0;
}