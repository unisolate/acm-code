#include <bits/stdc++.h>
using namespace std;
struct domino
{
    int l, r, id;
    bool dir;
} d[111];
bool cmp(domino a, domino b)
{
    if (a.l == b.l)
        return a.l - a.r < b.l - b.r;
    return a.l > b.l;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &d[i].l, &d[i].r);
        d[i].id = i;
        if (d[i].l < d[i].r)
        {
            swap(d[i].l, d[i].r);
            d[i].dir = true;
        }
    }
    return 0;

}