#include <bits/stdc++.h>
using namespace std;
struct t
{
    int s;
    string x, y;
} p[111];
int cmp(t a, t b)
{
    if (a.x[0] == b.x[0])
    {
        if (a.s == b.s)
            return a.y < b.y;
        return a.s < b.s;
    }
    return a.x[0] < b.x[0];
}
int m[256];
int main()
{
    m['P'] = 1, m['M'] = 2, m['G'] = 3;
    int n;
    bool f = false;
    while (scanf("%d", &n) && n)
    {
        getchar();
        if (f) putchar(10); else f = true;
        for (int i = 0; i < n; ++i)
        {
            getline(cin, p[i].y), getline(cin, p[i].x);
            p[i].s = m[p[i].x[p[i].x.size() - 1]];
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; ++i)
            cout << p[i].x << " " << p[i].y << endl;
    }
    return 0;
}