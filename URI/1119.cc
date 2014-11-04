#include <cstdio>
#include <cstring>
using namespace std;
bool f[22];
int main()
{
    int n, k, m;
    while (scanf("%d%d%d", &n, &k, &m) && n + k + m)
    {
        memset(f, false, sizeof(f));
        int t = n, a = 0, b = n + 1;
        while (t > 0)
        {
            for (int i = 0; i < k; ++i)
            {
                ++a;
                if (a > n) a = 1;
                while (f[a])
                {
                    ++a;
                    if (a > n) a = 1;
                }
            }
            for (int i = 0; i < m; ++i)
            {
                --b;
                if (b < 1) b = n;
                while (f[b])
                {
                    --b;
                    if (b < 1) b = n;
                }
            }
            f[a] = f[b] = true;
            if (a == b)
                --t, printf("%3d", a);
            else t -= 2, printf("%3d%3d", a, b);
            if (t > 0) putchar(',');
        }
        putchar(10);
    }
    return 0;
}