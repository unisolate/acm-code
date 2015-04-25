/*
n^2水过了竟然
树状数组做应该
*/
#include <bits/stdc++.h>
#define MX 16006
using namespace std;
int a[MX], b[MX];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i] > a[j] && b[i] < b[j])
            {
                ++ans;
                break;
            }
    printf("%d\n", ans);
    return 0;
}