#include <cstdio>
#include <map>
using namespace std;
int a[100001];
bool B(int v, int u)
{
    int l = 0, r = u, m;
    while (l <= r)
    {
        m = (l + r) >> 1;
        if (a[m] == v)
            return true;
        if (a[m] < v)
            l = m + 1;
        else r = m - 1;
    }
    return false;
}
int main()
{
    int n, l, x, y, v;
    bool fx = false, fy = false;
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if (!fx)
        {
            if (a[i] < x) continue;
            if (B(a[i] - x, i))
                fx = true;
        }
        if (!fy)
        {
            if (a[i] < y) continue;
            if (B(a[i] - y, i))
                fy = true;
        }
    }
    int p[2];
    if (fx && fy)
        v = 0;
    else if (fx && !fy)
        v = 1, p[0] = y;
    else if (!fx && fy)
        v = 1, p[0] = x;
    else
    {
        bool fq = false, fr = false;
        int q = y - x, r = x + y;
        for (int i = n - 1; i > 0; --i)
        {
            if (fq || fr)
                break;
            if (a[i] - q >= 0 && B(a[i] - q, i))
            {
                if (a[i] - y >= 0)
                {
                    fq = true;
                    v = 1;
                    p[0] = a[i] - y;
                }
                else if (a[i] + x <= a[n - 1])
                {
                    fq = true;
                    v = 1;
                    p[0] = a[i] + x;
                }
            }
            if (a[i] - r >= 0 && B(a[i] - r, i))
            {
                fr = true;
                v = 1;
                p[0] = a[i] - y;
            }
        }
        if (!fq && !fr)
        {
            v = 2;
            p[0] = x;
            p[1] = y;
        }
    }
    printf("%d\n", v);
    for (int i = 0; i < v; ++i)
        printf("%d ", p[i]);
    return 0;
}