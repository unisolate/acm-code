#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1111];
int n, f[1111], a[1111];
void init(int p)
{
    f[0] = 0; f[1] = 0;
    for (int i = 1; i < n - p; ++i)
    {
        int j = f[i];
        while (j && s[i + p] != s[j + p])
            j = f[j];
        f[i + 1] = (s[i + p] == s[j + p] ? j + 1 : 0);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        memset(a, 0, sizeof(a));
        scanf("%s", s);
        n = strlen(s);
        for (int i = 0; i < n; ++i)
        {
            init(i);
            // printf("##\n");
            for (int j = 2; j <= n - i; ++j)
            {
                for (int k = f[j]; k > 0; k = f[k])
                    if (j % (j - k) == 0)
                    {
                        // printf("%d %d\n", j, j / (j - f[j]));
                        a[j / (j - k)] = max(a[j / (j - k)], j);
                    }
            }
        }
        a[1] = n;
        printf("Case #%d:", cas);
        for (int i = 1; i <= n; ++i)
            printf(" %d", a[i]);
        putchar(10);
    }
    return 0;
}