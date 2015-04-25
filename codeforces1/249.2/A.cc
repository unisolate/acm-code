#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n, m, a, t = 0, ans = 1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        if (t + a > m)
        {
            t = a;
            ans++;
        }
        else t += a;
    }
    printf("%d\n", ans);
    return 0;
}