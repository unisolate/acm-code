#include <bits/stdc++.h>
#define MAXN 5050
#define INF 1000000001
using namespace std;
int a[MAXN];
int query(int l, int r)
{
    int ans = INF;
    for (int i = l; i <= r; ++i)
        if (a[i] < ans)
            ans = a[i];
    return ans;
}
int solve(int l, int r, int b)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    int m = query(l, r);
    if (m > b)
        return min(m - b + solve(l, r, m), r - l + 1);
    else if (m == b)
    {
        int ans = 0, p = l;
        for (int i = l; i <= r; ++i)
            if (a[i] == m)
            {
                ans += solve(p, i - 1, b);
                p = i + 1;
            }
        ans += solve(p, r, b);
        return ans;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    printf("%d\n", solve(1, n, 0));
    return 0;
}