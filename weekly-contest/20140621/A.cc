#include <cstdio>
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        char c = 'a';
        printf("2 %d %d\n", n, n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                printf("%c", c);
            c++;
            if (c > 'z')
                c = 'A';
            putchar(10);
        }
        putchar(10);
        for (int i = 0; i < n; ++i)
        {
            c = 'a';
            for (int j = 0; j < n; ++j)
            {
                printf("%c", c);
                c++;
                if (c > 'z')
                    c = 'A';
            }
            putchar(10);
        }
    }
    return 0;
}