#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 111111
using namespace std;
char p[MX], op[3];
int c[30][MX];
void U(int x, int i, int v)
{
    ++i;
    for (; i > 0; i -= (i & -i))
        c[x][i] += v;
}
int Q(int x, int i)
{
    ++i;
    int r = 0;
    for (; i < MX; i += (i & -i))
        r += c[x][i];
    return r;
}
int main()
{
    int t, n, q, l, r, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        scanf("%s%d", p, &q);
        int l = strlen(p);
        for (int i = 0; i < l; ++i)
            U(p[i] - 'A', i, 1);
        printf("Case #%d:\n", ++cas);
        while (q--)
        {
            scanf("%s%d%d", op, &l, &r);
            if (op[0] == 's')
            {
                for (int i = l; i <= r; ++i)
                {
                    U(p[i] - 'A', i, -1);
                }
                sort(p + l, p + l + r);
                for (int i = l; i <= r; ++i)
                {
                    U(p[i] - 'A', i, 1);
                }
            }
            else
            {
                for (int i = 0; i < 25; ++i)
                    printf("%d ", Q(i, l) - Q(i, r + 1));
                printf("%d\n", Q(25, l) - Q(25, r + 1));
            }
        }
    }
    return 0;
}