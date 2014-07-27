/*
13.05.14 20:28	15 ms	58 kb
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct leaf
{
    int t, l;
} p[111];
int cmp(leaf a, leaf b)
{
    // if(a.l==b.l)
    //  return a.t<b.t;
    return a.l > b.l;
}
int main()
{
    int n, s = 0, k = -1, st = 0, ml = -1, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i].t, st += p[i].t;
    for (int i = 0; i < n; ++i)
        cin >> p[i].l;
    sort(p, p + n, cmp);
    ans = st + p[n - 1].l;
    for (int i = 0; i < n; ++i)
    {
        s += p[i].t;
        if (s + p[i].l > ans)
            ans = s + p[i].l;
    }
    cout << ans << endl;
    return 0;
}