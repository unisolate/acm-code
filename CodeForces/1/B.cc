#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char s[100];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        int len = strlen(s), p = 0, f = 0;
        for (int i = 0; i < len; ++i)
        {
            if (!f && s[i] >= '0' && s[i] <= '9')
                f = i;
            if (f && s[i] >= 'A' && s[i] <= 'Z')
            {
                p = i;
                break;
            }
        }
        if (p)
        {
            int n = 0, t = 1;
            for (int i = len - 1; i > p; --i)
                n += (s[i] - '0') * t, t *= 10;
            int q[10], z = 0;
            while (n > 0)
            {
                q[z++] = ((n % 26) ? n % 26 : 26) + 'A' - 1;
                n = n / 26 + ((n % 26) ? 0 : -1);
            }
            for (int i = z - 1; i >= 0; --i)
                printf("%c", q[i]);
            for (int i = 1; i < p; ++i)
                printf("%c", s[i]);
            putchar(10);
        }
        else
        {
            printf("R");
            for (int i = f; i < len; ++i)
                printf("%c", s[i]);
            printf("C");
            int n = 0, t = 1;
            for (int i = f - 1; i >= 0; --i)
                n += (s[i] - 'A' + 1) * t, t *= 26;
            printf("%d\n", n);
        }
    }
    return 0;
}
// R228C494
// wrong answer 56th words differ - expected: 'RZ228', found: 'S@228'
