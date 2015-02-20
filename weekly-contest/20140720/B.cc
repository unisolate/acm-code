#include <cstdio>
#include <algorithm>
using namespace std;
int p[100100];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        int m = p[0], ans = p[0] - p[1];
        for (int i = 1; i < n; ++i)
        {
            ans = max(ans, m - p[i]);
            m = max(m, p[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}