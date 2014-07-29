#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 1010
using namespace std;
char a[MX], b[MX];
int p[MX], q[MX];
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));
        scanf("%s%s", a, b);
        int la = strlen(a), lb = strlen(b);
        for (int i = 1; i <= la; ++i)
            p[i] = a[la - i] - '0';
        for (int i = 1; i <= lb; ++i)
            q[i] = b[lb - i] - '0';
        int l = max(la, lb), add = 0;
        for (int i = 1; i <= l; ++i)
        {
            p[i] += q[i] + add;
            add = p[i] / 10;
            p[i] %= 10;
        }
        if (cas)
            putchar(10);
        printf("Case %d:\n%s + %s = ", ++cas, a, b);
        if (add == 1)
            printf("1");
        while (l)
            printf("%d", p[l--]);
        putchar(10);
    }
    return 0;
}