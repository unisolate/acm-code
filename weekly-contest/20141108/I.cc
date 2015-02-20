#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#define MX 11
using namespace std;
char s[MX][111];
char p[111];
int q[MX];
int main()
{
    int t, n, m, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s[i]);
            q[i] = strlen(s[i]);
        }
        printf("Case #%d:\n", ++cas);
        while (m--)
        {
            bool f = false;
            scanf("%s", p);
            int l = strlen(p), d = 0;
            for (int i = 0; i < n; ++i)
            {
                if (q[i] == l)
                {
                    int c = 0;
                    for (int j = 0; j < l; ++j)
                    {
                        if (s[i][j] != p[j])
                            ++c;
                    }
                    if (c == 0)
                        f = true;
                    else if (c == 1)
                        ++d;
                }
            }
            if (d == 1) f = true;
            if (f) puts("yes"); else puts("no");
        }
    }
    return 0;
}