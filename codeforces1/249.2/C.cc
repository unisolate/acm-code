#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n, p[1111], x = 0, a = 0, b = 0, y = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i]);
        x += p[i];
        if (i % 2 == 0)
        {
            y += p[i];
            if (y > a)
                a = y;
        }
        else
        {
            y -= p[i];
            if (y < b)
                b = y;
        }
    }
    y = a - b;
    char s[y + 1][x + 1];
    for (int i = 0; i < y + 1; ++i)
        for (int j = 0; j < x + 1; ++j)
            s[i][j] = ' ';
    b = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2)
        {
            for (int j = 0; j < p[i]; ++j)
            {
                s[++a][b++] = '\\';
            }
        }
        else
        {
            for (int j = 0; j < p[i]; ++j)
            {
                s[a--][b++] = '/';
            }
        }
    }
    for (int i = 1; i < y + 1; ++i)
    {
        for (int j = 0; j < x; ++j)
            printf("%c", s[i][j]);
        putchar(10);
    }
    return 0;
}