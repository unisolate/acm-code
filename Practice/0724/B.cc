#include <cstdio>
char s[6][6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("a\nb\nc\n");
    else if (n * 6 > 100000)
        printf("TOO LONG\n");
    else
    {
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < n / 3; ++j)
                printf("%s", s[i]);
            for (int j = 0; j < n % 3; ++j)
                printf("%c", s[i][j]);
            putchar(10);
        }
    }
    return 0;
}