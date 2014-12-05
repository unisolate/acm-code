#include <cstdio>
using namespace std;
const long long MOD = 1000000009;
long long P(int x, int y)
{
    long long r = 1;
    for (int i = 0; i < y; ++i)
        r *= x, r = r % MOD;
    return r;
}
int main()
{
    long long s = 0;
    int n;
    scanf("%d", &n);
    s = P(3, n) - P(2, n + 1) + 1;
    if (s < 0) s += MOD;
    printf("%lld\n", s % MOD);
    return 0;
}