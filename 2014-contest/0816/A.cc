#include <bits/stdc++.h>
using namespace std;
int p[2222];
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]), p[i] = abs(p[i]);
    for (int i = 1; i <= n; ++i) {
        int a = 0, b = 0;
        for (int j = 1; j <= n; ++j)
            if (p[i] > p[j]) {
                if (i > j)++a;
                if (i < j)++b;
            }
        ans += min(a, b);
    }
    printf("%d", ans);
    return 0;
}