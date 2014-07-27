#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, a, b, ans = 0;
    int d[111];
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
        scanf("%d", &d[i]);
    scanf("%d%d", &a, &b);
    for (int i = a; i < b; ++i)
        ans += d[i];
    printf("%d\n", ans);
    return 0;
}