#include <bits/stdc++.h>
using namespace std;
char s[5000], x[256][256];
int dict[256][256], l[256];
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        printf("Case #%d:\n", cas);
        memset(dict, 0, sizeof(dict));
        memset(l, 0, sizeof(l));
        int n, m, len;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", x[i]);
            l[i] = strlen(x[i]);
            for (int j = 0; j < l[i]; ++j)
                ++dict[i][x[i][j]];
        }
        getchar();
        for (int i = 0; i < m; ++i)
        {
            gets(s);
            len = strlen(s);
            int pre = 0;
            for (int j = 0; j <= len; ++j)
            {
                if (s[j] == ' ' || j == len)
                {
                    int y = j - pre;
                    for (int k = 'a'; k <= 'z'; ++k)
                        dict[n][k] = 0;
                    for (int k = pre; k < j; ++k)
                        ++dict[n][s[k]];
                    for (int k = 0; k < n; ++k)
                    {
                        if (y == l[k])
                        {
                            bool flag = true;
                            for (int z = 'a'; z <= 'z'; ++z)
                            {
                                if (dict[n][z] != dict[k][z])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                printf("%s", x[k]);
                                if (j != len)
                                    printf(" ");
                                break;
                            }
                        }
                    }
                    pre = j + 1;
                }
            }
            putchar(10);
        }
    }
    return 0;
}