#include <cstdio>
#define MOD (int)1e8
using namespace std;
int f[22][22];
int main()
{
    int m, n;
    while (~scanf("%d%d", &m, &n))
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &f[i][j]);
        printf("%d\n", ans % MOD);
    }
    return 0;
}