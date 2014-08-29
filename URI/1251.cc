#include <bits/stdc++.h>
using namespace std;
struct f
{
    int v, d;
} p[256];
int cmp(f a, f b)
{
    if (a.v == b.v)
        return a.d > b.d;
    return a.v < b.v;
}
char s[1111];
int main()
{
    bool c = false;
    while (~scanf("%s", s))
    {
        if (c) putchar(10); else c = true;
        for (int i = 0; i < 256; ++i)
            p[i].v = 0, p[i].d = i;
        int l = strlen(s);
        for (int i = 0; i < l; ++i)
            ++p[s[i]].v;
        sort(p, p + 256, cmp);
        for (int i = 0; i < 256; ++i)
        {
            if (!p[i].v) continue;
            printf("%d %d\n", p[i].d, p[i].v);
        }
    }
    return 0;
}