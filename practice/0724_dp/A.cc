#include <cstdio>
#include <algorithm>
#define MX 1111
using namespace std;
int lis[MX];
int main()
{
    int n, j, x, len = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        j = lower_bound(lis + 1, lis + len + 1, x) - lis;
        lis[j] = x;
        len = max(len, j);
    }
    printf("%d\n", len);
    return 0;
}