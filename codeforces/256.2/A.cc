#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a1, a2, a3, b1, b2, b3, n;
    scanf("%d%d%d", &a1, &a2, &a3);
    scanf("%d%d%d%d", &b1, &b2, &b3, &n);
    int s1 = a1 + a2 + a3, s2 = b1 + b2 + b3;
    int k = s1 / 5 + ((s1 % 5 > 0) ? 1 : 0);
    int f = s2 / 10 + ((s2 % 10 > 0) ? 1 : 0);
    if (k + f > n)
        puts("NO");
    else puts("YES");
    return 0;
}