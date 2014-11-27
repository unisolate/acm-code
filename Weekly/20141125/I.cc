#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
struct team
{
    int pt, ac;
    int pb[30];
    string tn;
} x[50050];
int cmp(team a, team b)
{
    if (a.ac == b.ac)
        return a.pt < b.pt;
    return a.ac < b.ac;
}
int main()
{
    int t, cas = 0, n, m, p, q;
    scanf("%d", &t);
    while (t--)
    {
        map<string, int> mp;
        scanf("%d%d%d%d", &n, &m, &p, &q);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s%s%d%s");
        }
        printf("Case #%d:\n", ++cas);
        sort(x, x + mp.size(), cmp);
        for (int i = 0; i < mp.size(); ++i)
        {
            printf("%s %d ", x[i].tn, i + 1);
        }
    }
    return 0;
}