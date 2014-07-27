#include <cstdio>
#include <string.h>
#define MAXN 1111
using namespace std;
int f[MAXN][MAXN];
void update(int x, int y)
{
    for (; x <= MAXN; x += (x & -x))
        for (int i = y; i <= MAXN; i += (i & -i))
            f[x][i]++;
}
int read(int x, int y)
{
    int sum = 0;
    for (; x > 0; x -= (x & -x))
        for (int i = y; i > 0; i -= (i & -i))
            sum += f[x][i];
    return sum;
}
int main()
{
    int x, n, t, a, b, c, d;
    char op[2];
    scanf("%d", &x);
    while (x--)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d", &n, &t);
        while (t--)
        {
            scanf("%s", op);
            if (op[0] == 'Q')
            {
                scanf("%d%d", &a, &b);
                printf("%d\n", read(a, b) % 2);
            }
            else
            {
                scanf("%d%d%d%d", &a, &b, &c, &d);
                update(c + 1, d + 1);
                update(a, b);
                update(a, d + 1);
                update(c + 1, b);
            }
        }
        printf("\n");
    }
    return 0;
}