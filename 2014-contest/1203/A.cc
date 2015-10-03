#include <cstdio>
using namespace std;
char s[1111];
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                printf("%c", s[i * m + j]);
            }
            putchar(10);
        }
    }
    return 0;
}