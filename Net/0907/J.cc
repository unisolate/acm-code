#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char p[111], s[111];
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        bool flag = false;
        gets(p);
        int len = strlen(p), k = 0;
        for (int i = 0; i < len; ++i)
            if (isalpha(p[i]))
                s[k++] = p[i];
        s[k] = '\0';
        len = k;
        // printf("#%s\n%d\n", s, len);
        for (int a = 1; a < len; ++a)
        {
            for (int b = 1; b < len; ++b)
            {
                if (a + b + a + b >= len)
                    break;
                bool x = false;
                if (a == b)
                {
                    x = true;
                    for (int i = 0; i < a; ++i)
                        if (s[i] != s[i + a])
                            x = false;
                }
                if (x)
                    continue;
                bool f = true;
                for (int i = 0; i < a + b; ++i)
                {
                    if (a + b + i >= len || s[i] != s[a + b + i])
                    {
                        f = false;
                        // printf("%d %d %d\n", a, b, i);
                        break;
                    }
                }
                if (!f)
                {
                    // printf("####%d %d\n", a, b);
                    continue;
                }
                // printf("####%d %d\n", a, b);
                if (a + b + a + b + a == len)
                {
                    for (int i = 0; i < a; ++i)
                        if (s[i] != s[a + b + a + b + i])
                        {
                            f = false;
                            break;
                        }
                    if (f)
                    {
                        flag = true;
                        // printf("##%d %d\n", a, b);
                    }
                }
                if (a + b + a + b + a + b + 1 < len)
                {
                    for (int i = 0; i < a + b; ++i)
                    {
                        if (s[i] != s[len - a - b + i])
                        {
                            f = false;
                            break;
                        }
                    }
                    if (f)
                    {
                        bool y = false;
                        if (len - a - b - a - b - a - b == a)
                        {
                            y = true;
                            for (int i = 0; i < a; ++i)
                                if (s[i] != s[a + b + a + b + i])
                                {
                                    y = false;
                                }
                        }
                        if (len - a - b - a - b - a - b == b)
                        {
                            y = true;
                            for (int i = 0; i < b; ++i)
                                if (s[a + i] != s[a + b + a + b + i])
                                    y = false;
                        }
                        if (!y)
                        {
                            flag = true;
                            // printf("###%d %d\n", a, b);
                        }

                    }
                }
            }
        }
        if (flag)
            puts("Yes");
        else puts("No");
    }
    return 0;
}