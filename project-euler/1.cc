/*
Answer: 233168
*/
#include <cstdio>

// int solve()
// {
//     int sum = 0;
//     for (int i = 1; i < 1000; ++i)
//         if (i % 3 == 0 || i % 5 == 0)
//             sum += i;
//     return sum;
// }

long long sum1toN(long long n)
{
    return n * (n + 1) / 2;
}

long long sumMultpies(long long limit, int a)
{
    return a * sum1toN((limit - 1) / a);
}

int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", sumMultpies(n, 3) + sumMultpies(n, 5) - sumMultpies(n, 15));
    }

    //Solve 1
    // printf("%d\n", solve());

    //Solve 2
    // printf("%d\n", sumMultpies(1000, 3) + sumMultpies(1000, 5) - sumMultpies(1000, 15));
    return 0;
}