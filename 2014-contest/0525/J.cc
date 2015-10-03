#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, p, ans = 0;
    scanf("%d", &n);
    bool flag[5555];
    memset(flag, false, sizeof(flag));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p);
        flag[p - 1] = true;
    }
    for (int i = 0; i < n; ++i)
        if (!flag[i])
            ans++;
    printf("%d\n", ans);
    return 0;
}