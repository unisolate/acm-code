/*
11.05.14 20:14  31 ms   3970 kb
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000001
using namespace std;
int p[MAXN];
int main()
{
    memset(p, 0, sizeof(p));
    int n, m = 0, t, c;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t);
        p[t]++;
        m = max(m, t);
    }
    for (int i = m; i > 0; --i)
    {
        c = 0;
        for (int j = i; j <= m && c < 2; j += i)
            c += p[j];
        if (c > 1)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}