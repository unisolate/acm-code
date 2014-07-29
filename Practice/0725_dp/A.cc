#include <bits/stdc++.h>
#define MX 100010
#define L 678
using namespace std;
int p[MX], f[MX], m[MX];
int main()
{
    int n, t, T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        memset(f, 0, sizeof(f));
        memset(m, 0, sizeof(m));
        scanf("%d%d", &n, &t);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        for (int i = 0; i < n; ++i)
            for (int j = t; j >= p[i]; --j)
                if (f[j - p[i]] + p[i] > f[j] || (f[j - p[i]] + p[i] == f[j] && m[j - p[i]] + 1 >= m[j]))
                {
                    f[j] = f[j - p[i]] + p[i];
                    m[j] = m[j - p[i]] + 1;
                }
        printf("Case %d: %d %d\n", cas, m[t - 1] + 1, f[t - 1] + L);
    }
    return 0;
}
/*#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MN 50*3*160*2

int F[MN], T, N, M, t;

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