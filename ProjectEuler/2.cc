#include <cstdio>
long long solve(long long n)
{
    long long a = 2, b = 8, c = 34, d, sum = a + b;
    while (n >= c)
    {
        sum += c;
        d = b + 4 * c;
        a = b, b = c, c = d;
    }
    return sum;
}
int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}