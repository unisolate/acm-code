#include <cstdio>
#include <cstring>
#define MX (int)1e6
using namespace std;
char s[MX], a[MX], b[MX];
int m, n;
int main()
{
    int t, op, q;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%d", s, &q);
        int sb = strlen(s);
        n = 2 * sb;
        for (int i = 0; i < sb; ++i)
            a[i] = a[i + sb] = s[i];
        while (q--)
        {
            scanf("%d%s", &op, b);
            if (op == 1)
            {
                int len = strlen(b);
                for (int i = 0; i < len; ++i)
                    s[i + sb] = b[i];
                sb += len;
                for (int i = 0; i < sb; ++i)
                    a[i] = a[i + sb] = s[i];
                n = 2 * sb;
            }
            else
            {
                m = strlen(b);
                bool flag = false, f = true;
                int pos = 0, lim = n / 2;
                // for (int i = 0; i < n; ++i)
                //     printf("%c", a[i]);
                for (int i = 0; i < lim; ++i)
                {
                    if (a[i] == b[pos])
                    {
                        ++pos;
                        // printf("%d %d", i, pos);
                        if (f)
                        {
                            lim += i;
                            f = false;
                        }
                    }
                    if (pos == m)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}