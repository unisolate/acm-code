#include <cstdio>
#include <algorithm>
#define MX 11111
using namespace std;
int p[MX];
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; ++i)
        {
            while (p[i] != i)
                swap(p[i], p[p[i]]), ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}