#include <cstdio>
using namespace std;
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        long long ans = 0, p = 1;
        while (n > 0)
        {
            for (int i = 1; i <= n % 4; ++i)
                ans += ((i % 2) ? p : p * 2);
            n /= 4;
            ans += n * (4 * p);
            p *= 4;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}