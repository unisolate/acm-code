#include <cstdio>
#include <cstring>
using namespace std;
char s[2222];
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        gets(s);
        int l = strlen(s);
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == '0' || s[i] == ' ')
            {
                int c = 1;
                while (i + c < l && s[i + c] == s[i])
                    ++c;
                if (c == 1)
                {
                    printf("%c", s[i]);
                }
                else if (c == 2)
                {
                    printf("%c%c", s[i], s[i + 1]);
                }
                else
                {
                    for (int j = 0; j < c / 255; ++j)
                    {
                        if (s[i] == '0')
                            printf("#");
                        else printf("$");
                        printf("%c", 255);
                    }
                    if (s[i] == '0')
                        printf("#");
                    else printf("$");
                    printf("%c", c % 255);
                }
                i += c - 1;
            }
            else printf("%c", s[i]);
        }
        putchar(10);
    }
    return 0;
}