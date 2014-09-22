#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
struct P
{
    int a, b;
} p[1111111];
int cmp(P x, P y)
{
    return x.b > y.b;
}
int ans[1111111];
int main()
{
    int t, n, w, s, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        map<int, int> m;
        map<int, int>::iterator it;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &w);
            s = 10000 - (100 - w) * (100 - w);
            m[s]++;
        }
        it = m.begin();
        int k = it->second, pos = 0;
        bool flag = true;
        for (it = m.begin(); it != m.end(); ++it)
        {
            p[pos].a = it->first;
            p[pos++].b = it->second;
            if (p[pos - 1].b != k)
                flag = false;
        }
        sort(p, p + pos, cmp);
        if (pos == 1)
            flag = false;
        printf("Case #%d:\n", ++cas);
        if (flag)
            printf("Bad Mushroom\n");
        else
        {
            int pa = 0, pp = 0, tmp = p[0].b;
            ans[pa++] = p[pp++].a;
            while (pp != pos && p[pp].b == tmp)
            {
                ans[pa++] = p[pp].a;
                ++pp;
            }
            sort(ans, ans + pa);
            printf("%d", ans[0]);
            for (int i = 1; i < pa; ++i)
                printf(" %d", ans[i]);
            putchar(10);
        }
    }
    return 0;
}