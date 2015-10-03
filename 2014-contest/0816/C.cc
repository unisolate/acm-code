#include <bits/stdc++.h>
#define MX 5555
using namespace std;
typedef unsigned long long ull;
const ull B = 100000007ULL;
char s[MX];
ull ha[MX];
int f[MX][MX], damn[MX][MX];
ull get1(int l, int r)
{
    return ha[r] - ha[l] * bp[r - l];
}
ull get2(int l, int r)
{
    return;
}
int shit(int l, int r)
{
    if (damn[l][r] != -1)
        return damn[l][r];
    int m = l + r >> 1;
    if ((l + r) % 2)
    {
        if (get1(l, m) == get2(m + 1, r))
        {
            for (int i = 0; l + i <= m; ++i)
                damn[l + i][r - i] = 1;
        }
        else damn[l][r] = 0;
    }
    else
    {
        if (get1(l, m - 1) == get2(m + 1, r))
        {
            for (int i = 0; l + i <= m - 1; ++i)
                damn[l + i][r - i] = 1;
        }
        else damn[l][r] = 0;
    }
    return damn[l][r];
}
int fuck(int l, int r)
{
    if (f[l][r] != -1)
        return f[l][r];
    f[l][r] = 0;
    if (shit(l, r) == 1)
        f[l][r] = 1;
    return f[l][r] += fuck(l - 1, r + 1) + fuck(l, r - 1) + fuck(l + 1, r);
}
int main()
{
    int q, l, r;
    memset(damn, -1, sizeof(damn));
    memset(f, -1, sizeof(f));
    scanf("%s%d", s, &q);
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
        ha[i] = ha[i - 1] * B + s[i];
    while (q--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", fuck(l - 1, r - 1));
    }
    return 0;
}