#include <cstdio>
int main()
{
    long long n;
    while (~scanf("%I64d", &n))
        printf("%I64d\n\n", n * (n + 1) / 2);
    return 0;
}