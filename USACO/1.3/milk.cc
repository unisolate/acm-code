/*
ID: unisola1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int p, a;
} c[5555];
int cmp(struct node a, struct node b)
{
    return a.p < b.p;
}
int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int n, m, k = 0, ans = 0;
    cin >> n >> m;
    if (n == 0 || m == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> c[i].p >> c[i].a;
    }
    sort(c, c + m, cmp);
    int i = 0;
    while (k < n)
    {
        if (n - k >= c[i].a)
        {
            ans += c[i].p * c[i].a;
        }
        else
        {
            ans += (n - k) * c[i].p;
        }
        k += c[i].a;
        i++;
    }
    cout << ans << endl;
    return 0;
}