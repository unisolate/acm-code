#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;
int n, a[MAXN], b[MAXN], c[MAXN], f[MAXN];
// bool f(int p, int k)
// {
//     if (p == n)
//     {
//         if (k == 0)
//             return true;
//         return false;+
//     }
//     if (f(p + 1, k + a[p]))
//     {
//         b[p] = -1;
//         return true;
//     }
//     if (f(p + 1, k - a[p]))
//     {
//         b[p] = 1;
//         return true;
//     }
//     return false;
// }
int main()
{
    while (~scanf("%d", &n))
    {
        memset(f, 0, sizeof(f));
        memset(c, -1, sizeof(c));
        long long s = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]), s += a[i];
        if (s % 2)
        {
            puts("No");
            continue;
        }
        int v = s / 2;
        // for (int i = 1; i < MAXN; ++i)
        //     c[i] = -INF;
        c[0] = 0;
        for (int i = n - 1; i >= 0; --i)
            for (int j = v; j >= a[i]; --j)
            {
                // c[j] = max(c[j], c[j - a[i]] + a[i]);
                if (c[j - a[i]] != -1 && c[j] == -1)
                    c[j] = a[i];
            }
        printf("%d\n", c[v]);
        int k = v;
        while (c[k] == -1)
            --k;
        int t = k;
        while (k)
        {
            printf("%d ", c[k]);
            ++f[c[k]];
            k -= c[k];
        }
        printf("%d\n", t);
        for (int i = 0; i < n; ++i)
        {
            if (f[a[i]])
            {
                printf("1");
                --f[a[i]];
            }
            else printf("-1");
            if (i != n - 1)
                printf(" ");
        }
        putchar(10);
        // if (f(0, 0))
        // {
        //     puts("Yes");
        //     for (int i = 0; i < n - 1; ++i)
        //         printf("%d ", b[i]);
        //     printf("%d\n", b[n - 1]);
        // }
        // else puts("No");
    }
    return 0;
}