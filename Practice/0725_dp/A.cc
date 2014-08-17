#include <bits/stdc++.h>
#define MX 100010
using namespace std;
int f[MX];
int main()
{
    int n, m, t, T, cas = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(f, -1, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &t);
            for (int j = m - t; j >= 0; --j)
                if (f[j] != -1)
                    f[j + t] = max(f[j + t], f[j] + 1);
        }
        int x = 0, y = 0;
        for (int i = m - 1; i >= 0; --i)
            if (f[i] > x) x = f[i], y = i;
        printf("Case %d: %d %d\n", ++cas, x + 1, y + 678);
    }
    return 0;
}
/*int F[MN], T, N, M, t;
int main()
{
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= M; i++) F[i] = -1;
        F[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &t);
            for (int j = M - t; j >= 0; j--)
                if (F[j] != -1)
                    F[j + t] = max(F[j + t], F[j] + 1);
        }
        int a1 = 0, a2 = 0;
        for (int i = M - 1; i >= 0; i--)
            if (F[i] > a1) a1 = F[i], a2 = i;
        printf("Case %d: %d %d\n", cases, a1 + 1, a2 + 678);
    }
}*/