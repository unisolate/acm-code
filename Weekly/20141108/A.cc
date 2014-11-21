#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t, n, cas = 0, a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i)
            scanf("%d%d", &a, &b);
        if (n == 1)
            printf("Case #%d: 1\n", ++cas);
        else printf("Case #%d: 2\n", ++cas);
    }
    return 0;
}