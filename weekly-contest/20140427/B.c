#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        float ans = m * n;
        if (m % 2 && n % 2)
        {
            ans += 0.41;
        }
        printf("Scenario #%d:\n%.2f\n\n", cas, ans);
    }
    return 0;
}