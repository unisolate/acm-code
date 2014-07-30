#include <bits/stdc++.h>
#define MX 100
using namespace std;
char m[MX], n[MX];
long long c(char *s, int p)
{
    if (p == 0)
        return 1;
    return (s[p] - '0') * c(s, p - 1);
}
int main()
{
    while (~scanf("%s%s", m, n) && m[0] != '-')
        printf("%lld\n", c(n, strlen(n) - 1) - c(m, strlen(m) - 1));
    return 0;
}