#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1001
#define INF 1<<30
using namespace std;
char line[MAXN];
int d[MAXN];
int dp(int r)
{
    if (r < 0)
        return 0;
    if (d[r])
        return d[r];
    int i;
    d[r] = dp(r - 1) + 1;
    for (i = r - 1; i >= 0; --i)
    {
        if (hw(i, r))
            d[r] = min(d[r], dp(i - 1) + 1);
    }
    return d[r];
}
int hw(int l, int r)
{
    while (l < r)
    {
        if (line[l] == line[r])
        {
            l++;
            r--;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    int t, i;
    scanf("%d", &t);
    while (t--)
    {
        memset(d, 0, sizeof(d));
        d[0] = 1;
        scanf("%s", line);
        dp(strlen(line) - 1);
        printf("%d\n", d[strlen(line) - 1]);
    }
    return 0;
}