#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char s[1111];
double pw(int a, int b)
{
    double ret = 1;
    for (int i = 0; i < b; ++i)
        ret *= a;
    return ret;
}
int main()
{
    // for (int i = 1; i < 25; ++i)
    //     printf("%lld\n", pw(5, i));
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        // int l = strlen(s);
        int p = 0, num = 0;
        while (s[p] != '[')
        {
            ++p;
        }
        int k = 1;
        for (int i = 0; i < p; ++i)
        {
            num += k * (s[p - i - 1] - '0');
            k *= 10;
        }
        // printf("%d\n", num);
        // printf("%lld\n", pw(5, 24));
        double ans = 0.0;
        switch (s[p + 1])
        {
        case 'B':
            ans = 1;
            break;
        case 'K':
            ans = pw(5, 3) / pw(2, 7);
            break;
        case 'M':
            ans = pw(5, 6) / pw(2, 14);
            break;
        case 'G':
            ans = pw(5, 9) / pw(2, 21);
            break;
        case 'T':
            ans = pw(5, 12) / pw(2, 28);
            break;
        case 'P':
            ans = pw(5, 15) / pw(2, 35);
            break;
        case 'E':
            ans = pw(5, 18) / pw(2, 42);
            break;
        case 'Z':
            ans = pw(5, 21) / pw(2, 49);
            break;
        case 'Y':
            ans = pw(5, 24) / pw(2, 56);
            break;
        }
        printf("Case #%d: %.2lf%%\n", ++cas, ((1.0 - ans) * 100));
    }
    return 0;
}