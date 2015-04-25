#include <bits/stdc++.h>
#define MX (int)1e5
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
    int n, m, w, op, a, b, c, d, v;
    scanf("%d%d%d", &n, &m, &w);
    while (w--)
    {
        scanf("%d%d%d%d%d", &op, &a, &b, &c, &d);
        if (op)
        {

        }
        else
        {

        }
    }
    return 0;
}