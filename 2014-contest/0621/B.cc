#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
using namespace std;
long long p[55555];
int main()
{
    int n;
    long long s = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%I64d", &p[i]);
        s += p[i];
    }
    long long k = s / n;
    for (int i = 0; i < n - 1; ++i)
    {
        ans += (k - p[i] > 0) ? (k - p[i]) : (p[i] - k);
        p[i + 1] -= k - p[i];
    }
    printf("%I64d\n", ans);
    return 0;
}