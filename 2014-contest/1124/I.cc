#include <cstdio>
using namespace std;
int main()
{
    int n;
    long long ans = 1;
    for (int i = 1; i <= 500; ++i)
        ans = ans * (500 + i) / i;
    printf("%d\n", (1 ^ 2 ^ 10) + (1 ^ 2 ^ 1) + (1 ^ 10 ^ 1) + (2 ^ 10 ^ 1));
    for (int i = 0; i <= 10; ++i)
    {
        for (int j = 0; j <= 10; ++j)
            printf("%4d", i ^ j);
        putchar(10);
    }
    while (~scanf("%d", &n))
    {
        // for (int i = 0; i < n; ++i)
        // scanf("%d", &c[i]);
    }
    return 0;
}