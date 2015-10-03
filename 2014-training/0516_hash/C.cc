#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 1000005
using namespace std;
typedef unsigned long long ull;
const ull B = 100000007ULL;
char s[MX];
ull ha[MX];
int len[MX], b[MX];
int run(int x, int y)
{
    int l = 0, r = min(len[x], len[y]), m;
    while (l < r)
    {
        m = (l + r + 1) >> 1;
        if (ha[b[x] + m - 1] == ha[b[y] + m - 1])
            l = m;
        else r = m - 1;
    }
    return l;
}
int main()
{
    int t, cas = 1, n, x, y;
    scanf("%d", &t);
    while (t--)
    {
        printf("Case %d:\n", cas++);
        scanf("%d", &n);
        int p = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s + p);
            len[i] = strlen(s + p);
            b[i] = p;
            ha[p] = s[p];
            for (int j = 1; j < len[i]; ++j)
                ha[p + j] = ha[p + j - 1] * B + s[p + j];
            p += len[i];
        }
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", run(x - 1, y - 1));
        }
    }
    return 0;
}