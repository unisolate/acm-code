#include <cstdio>
#define MX 1111
using namespace std;
typedef unsigned long long ull;
char s[MX][MX], p[MX][MX];
ull ha[MX][MX];
int x, y;
void hash(char a[][MX], int n, int m)
{
    ull B = 2333, t = 1;
    for (int j = 0; j < y; ++j)
        t *= B;
    for (int i = 0; i < n; i++)
    {
        ull e = 0;
        for (int j = 0; j < y; j++)
            e = e * B + a[i][j];
        for (int j = 0; j <= m - y; j++)
        {
            ha[i][j] = e;
            if (j < m - y)
                e = e * B - t * a[i][j] + a[i][j + y];
        }
    }
    B = 100000007;
    t = 1;
    for (int i = 0; i < x; ++i)
        t *= B;
    for (int j = 0; j <= m - y; j++)
    {
        ull e = 0;
        for (int i = 0; i < x; ++i)
            e = e * B + ha[i][j];
        for (int i = 0; i <= n - x; i++)
        {
            ull c = e;
            if (i < n - x)
                e = e * B - t * ha[i][j] + ha[i + x][j];
            ha[i][j] = c;
        }
    }
}
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        scanf("%d%d", &x, &y);
        for (int i = 0; i < x; ++i)
            scanf("%s", p[i]);
        hash(p, x, y);
        ull h = ha[0][0];
        hash(s, n, m);
        for (int i = 0; i <= n - x; ++i)
            for (int j = 0; j <= m - y; ++j)
                if (ha[i][j] == h)
                    ans++;
        printf("%d\n", ans);
    }
    return 0;
}