#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, d, n1, n2, d1, d2;
    char x[9], y[9], z[9];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s%d%s%d%s%d", &n1, &x, &d1, &y, &n2, &z, &d2);
        if (y[0] == '+')
            n = n1 * d2 + n2 * d1, d = d1 * d2;
        else if (y[0] == '-')
            n = n1 * d2 - n2 * d1, d = d1 * d2;
        else if (y[0] == '*')
            n = n1 * n2, d = d1 * d2;
        else n = n1 * d2, d = n2 * d1;
        bool f = false;
        if ((n < 0 && d > 0) || (n > 0 && d < 0)) f = true;
        n = abs(n), d = abs(d);
        int g = __gcd(n, d);
        if (f) putchar('-');
        printf("%d/%d = ", n, d);
        if (f) putchar('-');
        printf("%d/%d\n", n / g, d / g);
    }
    return 0;
}