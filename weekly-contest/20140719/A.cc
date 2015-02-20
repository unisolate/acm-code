#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000000000LL
using namespace std;
long long p[11111];
bool f[11111];
char s[100];
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        memset(p, 0, sizeof(p));
        memset(f, false, sizeof(f));
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            long long t = 1;
            if (s[0] != 'x')
            {
                for (int j = strlen(s) - 1; j >= 0; --j)
                {
                    p[i] += (s[j] - '0') * t;
                    t *= 10;
                }
            }
            else f[i] = true;
        }
        long long l = -3 * INF, r = 3 * INF;
        int flag = 0;
        for (int i = 0; i < n; ++i)
        {
            if (flag)
                break;
            if (f[i])
            {
                if (i % 2)
                {
                    long long c = -2 * INF, d = -2 * INF;
                    if (i - 1 >= 0)
                    {
                        if (f[i - 1])
                            flag = 2;
                        else c = p[i - 1];
                    }
                    if (i + 1 < n)
                    {
                        if (f[i + 1])
                            flag = 2;
                        else d = p[i + 1];
                    }
                    l = max(l, max(c, d) + 1);
                }
                else
                {
                    long long c = 2 * INF, d = 2 * INF;
                    if (i - 1 >= 0)
                    {
                        if (f[i - 1])
                            flag = 2;
                        else c = p[i - 1];
                    }
                    if (i + 1 < n)
                    {
                        if (f[i + 1])
                            flag = 2;
                        else d = p[i + 1];
                    }
                    r = min(r, min(c, d) - 1);
                }
            }
            else
            {
                if (i % 2)
                {
                    if (i - 1 >= 0 && (!f[i - 1]) && p[i - 1] >= p[i])
                        flag = 1;
                    if (i + 1 < n && (!f[i + 1]) && p[i + 1] >= p[i])
                        flag = 1;
                }
                else
                {
                    if (i - 1 >= 0 && (!f[i - 1]) && p[i - 1] <= p[i])
                        flag = 1;
                    if (i + 1 < n && (!f[i + 1]) && p[i + 1] <= p[i])
                        flag = 1;
                }
            }
        }
        if (flag == 1)
            printf("none");
        else if (flag == 2)
            printf("none");
        else if (flag == 0)
        {
            if (r == l)
                printf("%I64d\n", l);
            else if (r > l)
                printf("ambiguous");
            else if (r < l)
                printf("none");
        }
    }
    return 0;
}