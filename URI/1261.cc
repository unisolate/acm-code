#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[222];
    int m, n, p;
    map<string, int> a;
    scanf("%d%d", &m, &n);
    while (m--)
        scanf("%s%d", s, &p), a[s] = p;
    while (n--)
    {
        int q = 0;
        while (scanf("%s", s) && s[0] != '.')
            q += a[s];
        printf("%d\n", q);
    }
    return 0;
}