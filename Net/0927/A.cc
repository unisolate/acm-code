#include <cstdio>
using namespace std;
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        printf("Case #%d: ", ++cas);
        long long a, b, s = 0;
        scanf("%I64d%I64d", &a, &b);
        for (long long i = a; i <= b; ++i)
            s += i * i * i;
        printf("%I64d\n", s);
    }
    return 0;
}