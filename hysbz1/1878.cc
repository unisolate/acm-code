#include <bits/stdc++.h>
#define MX 55555
using namespace std;
int c[MX];
bool f[MX];
void U(int n)
{
    for (; n <= MX; n += (n & -n))
        ++c[n];
}
int Q(int n)
{
    int sum = 0;
    for (; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p);
        if (!f[p])
            U(p), f[p] = true;
    }
    scanf("%d", &m);
    while (m--)
        scanf("%d%d", &l, &r), printf("%d\n", Q(r) - Q(l));
    return 0;
}