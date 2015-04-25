#include <cstdio>
#include <algorithm>
#include <functional>
#define MX 100001
using namespace std;
int lis[MX];
int main()
{
    int n, j, x, cas = 1;
    while (~scanf("%d", &n) && n != -1)
    {
        int len = 1;
        lis[1] = n;
        while (scanf("%d", &x) && x != -1)
        {
            j = lower_bound(lis + 1, lis + len + 1, x, greater<int>()) - lis;
            lis[j] = x;
            len = max(len, j);
        }
        printf("Test #%d:\n", cas++);
        printf("  maximum possible interceptions: %d\n\n", len);
    }
    return 0;
}