#include <bits/stdc++.h>
using namespace std;
char n[100], s[100], text[4][10] = {"shata", "hajar", "lakh", "kuti"};
int step[4] = {1, 2, 2, 2};
int main()
{
    int cas = 0;
    while (~scanf("%s", s))
    {
        int len = strlen(s), p = 0;
        while (s[p] == '0')
            --len, ++p;
        for (int i = 0; i < len; ++i)
            n[i] = s[i + p];
        int t = len - 3;
        p = -1;
        while (t >= 0)
            t -= step[(++p) % 4];
        printf("%4d. ", ++cas);
        if (len == 0)
            printf("0");
        else if (len > 2)
        {
            int k = t + step[p % 4] + 1;
            for (int i = 0; i < t + step[p % 4] + 1; ++i)
                printf("%c", n[i]);
            printf(" %s", text[p % 4]);
            for (int i = p - 1; i >= 0; --i)
            {
                bool flag = false;
                if (n[k] == '0')
                {
                    if (i % 4 == 0)
                        flag = true;
                    else if (n[k + 1] == '0')
                        flag = true;
                    if (step[i % 4] == 2 && n[k + 1] != '0')
                        printf(" %c %s", n[k + 1], text[i % 4]);
                }
                else
                {
                    printf(" ");
                    for (int j = 0; j < step[i % 4]; ++j)
                        printf("%c", n[j + k]);
                    printf(" %s", text[i % 4]);
                }
                if (flag && (i % 4) == 3)
                    printf(" %s", text[3]);
                k += step[i % 4];
            }
            if (n[k] != '0' || n[k + 1] != '0')
                printf(" ");
            if (n[k] != '0')
                printf("%c%c", n[k], n[k + 1]);
            else if (n[k + 1] != '0')
                printf("%c", n[k + 1]);
        }
        else
        {
            if (len == 1)
                printf("%c", n[0]);
            else
            {
                if (n[0] == '0')
                    printf("%c", n[1]);
                else printf("%c%c", n[0], n[1]);
            }
        }
        putchar(10);
    }
    return 0;
}