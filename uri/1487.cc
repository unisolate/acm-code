#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int c[601];
int main()
{
    int n, t, d, p, x = 0;
    while (scanf("%d%d", &n, &t) && n + t)
    {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &d, &p);
            for (int j = d; j <= t; ++j)
                c[j] = max(c[j], c[j - d] + p);
        }
        printf("Instancia %d\n%d\n\n", ++x, c[t]);
    }
    return 0;
}