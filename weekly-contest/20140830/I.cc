#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
using namespace std;
char s[222][222];
char z[40000];
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                map<string, int> p;
                for (int x = 0; x + i < m; ++x)
                    for (int y = 0; y + j < n; ++y)
                    {
                        int k = 0;
                        for (int u = x; u <= x + i; ++u)
                            for (int v = y; v <= y + j; ++v)
                                z[k++] = s[u][v];
                        z[k] = '\0';
                        // printf("%s %d\n", z, p[z]);
                        if (p[z] == 0) ++ans, ++p[z];
                    }
            }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}