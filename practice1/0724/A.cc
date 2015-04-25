#include <cstdio>
int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d %d\n", n - (n & -n) + 1, n + (n & -n) - 1);
    }
    return 0;
}