#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        char x[10];
        long long ans;
        scanf("%d%s%d", &a, x, &b);
        if (x[0] == '+')
            ans = a + b;
        if (x[0] == '-')
            ans = a - b;
        if (x[0] == '*')
            ans = a * b;
        printf("%lld\n", ans);
    }
    return 0;
}