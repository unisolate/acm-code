#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 111
using namespace std;
char p[MX][MX];
// bool v[MX][MX];
int x[9] = {1, 1, 1, 0, -1, -1, -1, 0};
int y[9] = {1, 0, -1, -1, -1, 0, 1, 1};
int main()
{
    int n, d[9];
    while (scanf("%d", &n) && n)
    {
        int ans = -1;
        // memset(v, false, sizeof(v));
        for (int i = 0; i < n; ++i)
            scanf("%s", p[i]);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // if (v[i][j])
                //     continue;
                // int t = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int a = i, b = j;
                    d[k] = -1;
                    while (a >= 0 && a < n && b >= 0 && b < n && p[a][b] != '#')
                        a += x[k], b += y[k], ++d[k];
                }
                ans = max(ans, max(d[0] + d[2], max(d[0] + d[6], max(d[4] + d[2], max(d[4] + d[6], max(d[1] + d[3], max(d[1] + d[7], max(d[5] + d[3], d[5] + d[7]))))))));
                // v[i][j] = true;
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}