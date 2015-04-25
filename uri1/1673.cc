#include <cstdio>
#include <cstring>
using namespace std;
char s[1000001];
int main()
{
    while (gets(s))
    {
        int l = strlen(s), c = 1, p = 0;
        bool f = (s[0] == s[1] ? true : false);
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == s[i + 1])
            {
                ++c;
                if (!f)
                {
                    f = true;
                    if (p < i)
                    {
                        putchar('1');
                        for (int j = p; j < i; ++j)
                        {
                            putchar(s[j]);
                            if (s[j] == '1') putchar('1');
                        }
                        putchar('1');
                    }
                }
            }
            else
            {
                if (f)
                {
                    p = i + 1;
                    f = false;
                    while (c > 9)
                    {
                        printf("9%c", s[i]);
                        c -= 9;
                    }
                    if (c > 1)
                    {
                        printf("%d%c", c, s[i]);
                    }
                    else if (c == 1)
                    {
                        printf("1%c1", s[i]);
                        if (s[i] == '1') putchar('1');
                    }
                    c = 1;
                }
            }
        }
        if (p < l)
        {
            putchar('1');
            for (int j = p; j < l; ++j)
            {
                putchar(s[j]);
                if (s[j] == '1') putchar('1');
            }
            putchar('1');
        }
        putchar(10);
    }
    return 0;
}