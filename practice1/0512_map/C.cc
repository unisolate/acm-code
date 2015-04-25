#include <iostream>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
typedef map<int, multiset<int> > mp;
void pop(mp &p, mp &q, int k)
{
    printf("%d\n", p[k].size());
    for (multiset<int>::iterator it = p[k].begin(); it != p[k].end(); ++it)
        q[*it].erase(k);
    p[k].clear();
}
int main()
{
    int n, m, x, y;
    while (scanf("%d%d", &n, &m) && n && m)
    {
        mp p, q;
        while (n--)
        {
            scanf("%d%d", &x, &y);
            p[x].insert(y);
            q[y].insert(x);
        }
        while (m--)
        {
            scanf("%d%d", &x, &y);
            if (x)
                pop(q, p, y);
            else pop(p, q, y);
        }
        putchar(10);
    }
    return 0;
}