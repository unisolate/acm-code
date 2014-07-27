#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
char s[MAXN], r[MAXN];
bool f[MAXN];
int main()
{
    int d, n;
    while (~scanf("%d%d", &d, &n) && d + n)
    {
        memset(f, false, sizeof(f));
        scanf("%s", s);
        strcpy(r, s);
        sort(r, r + d);
        int m = r[n], c = 0;
        n = d - n;
        for (int i = 0; i < d; ++i)
            if (s[i] > m)
                f[i] = true, ++c;
        for (int i = d - 1; i >= 0 && c < n; --i)
            if (s[i] == m)
                f[i] = true, ++c;
        c = 0;
        for (int i = 0; i < d && c < n; ++i)
            if (f[i])
                printf("%c", s[i]), ++c;
        putchar(10);
        int m = s[0];
        for (int i = 0; i < d - n; ++i)
            m = max(m, s[i]);
    }
    return 0;
}