#include <cstdio>
#include <map>
#include <vector>
#define MX 111111
using namespace std;
int p[MX];
int main()
{
    int n, m, k, v;
    while (~scanf("%d%d", &n, &m))
    {
        int c = 0;
        vector<int> s[MX];
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &p[i]);
            if (!mp[p[i]])
                mp[p[i]] = ++c;
            s[mp[p[i]]].push_back(i + 1);
        }
        while (m--)
        {
            scanf("%d%d", &k, &v);
            if (mp[v] && s[mp[v]].size() >= k)
                printf("%d\n", s[mp[v]][k - 1]);
            else printf("0\n");
        }
    }
    return 0;
}