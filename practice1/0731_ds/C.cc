#include <cstdio>
#include <cstring>
#define MX 1111
using namespace std;
int f[MX][MX];
void update(int x, int y)
{
    for (; x <= MX; x += (x & -x))
        for (int i = y; i <= MX; i += (i & -i))
            ++f[x][i];
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
    int t, n, k, a, b, c, d;
    char op[2];
    scanf("%d", &t);
    while (t--)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d", &n, &k);
        while (k--)
        {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'C')
            {
                scanf("%d%d", &c, &d);
                update(c + 1, d + 1);
                update(a, b);
                update(a, d + 1);
                update(c + 1, b);
            }
            else
                printf("%d\n", read(a, b) % 2);
        }
        putchar(10);
    }
    return 0;
}