#include <cstdio>
#define MX 2222
using namespace std;
char l[MX], w[MX];
long long gcd(long long a, long long b)
{
    return (b ? gcd(b, a % b) : a);
}
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%s", l, w);
        long long a = c(l), b = c(w);
        long long x = gcd(a, b);
        printf("Case #%d: %s\n", ++cas,);
    }
    return 0;
}