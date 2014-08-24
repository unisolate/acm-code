#include <bits/stdc++.h>
#define MX 11111
using namespace std;
int p[MX][2];
int w(int i)
{
    int x = (p[i][0] ? w(p[i][0]) : 0), y = (p[i][1] ? w(p[i][1]) : 0);
    return min(max(x + 1, y), max(x, y + 1));
}
int main()
{
    int n, t;
    while (~scanf("%d", &n))
    {
        memset(p, 0, sizeof(p));
        for (int i = 2; i <= n; ++i)
        {
            scanf("%d", &t);
            if (p[t][0]) p[t][1] = i;
            else p[t][0] = i;
        }
        printf("%d\n", w(1));
    }
    return 0;
}