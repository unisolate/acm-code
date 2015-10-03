#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
const int MS = 3333, MX = 15;
char s[MS][MX];
int main()
{
    int n, m, t, k;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        map<string, int> mp;
        scanf("%d%d", &m, &n);
        getchar();
        for (int i = 0; i < m + n; ++i)
            gets(s[i]);
        for (int i = 0; i < m; ++i)
            for (int j = m; j < m + n; ++j)
            {
                string t = "";
                for (int l = 0; l < strlen(s[i]); ++l)
                    t += s[i][l];
                for (int l = 0; l < strlen(s[j]); ++l)
                    t += s[j][l];
                mp[t]++;
            }
        printf("Case %d: %d\n", cas, mp.size());
    }
    return 0;
}