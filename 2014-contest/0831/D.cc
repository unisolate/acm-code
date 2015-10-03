#include <cstdio>
#include <cstring>
using namespace std;
int p[10];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int ans = 0, t, z;
        for (int i = n; i <= m; ++i)
        {
            memset(p, 0, sizeof(p));
            bool f = true;
            z = i;
            while (z)
            {
                t = z % 10;
                ++p[t];
                if (p[t] > 1)
                {
                    f = false;
                    break;
                }
                z /= 10;
            }
            if (f) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}