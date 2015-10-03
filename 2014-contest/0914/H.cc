#include <cstdio>
#include <cstring>
using namespace std;
const int mx = 111111;
int a[mx], b[mx], p[mx];
bool vis[mx];
int main()
{
    int n, i, j, pos, x, sum;
    long long ans;
    while (~scanf("%d", &n))
    {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i <= n; ++i)
            scanf("%d", &p[i]);
        ans = 0;
        for (i = n; i >= 0; i--)
        {
            if (vis[i])continue;
            x = i, pos = 0;
            while (x)
            {
                b[pos++] = x & 1;
                x = x >> 1;
            }
            //        for(j=0; j<pos; j++)
            //            printf("%d\n",b[j]);
            sum = 0;
            for (j = 0; j < pos; j++)
            {
                if (b[j] == 0)sum += (1 << j);
            }
            vis[sum] = vis[i] = true;
            a[sum] = i;
            a[i] = sum;
            ans += ((sum ^ i) * 2);
            //printf("cp >> %d %d %d\n",ans,sum,i);
        }
        printf("%lld\n", ans);
        for (i = 0; i < n; i++)
            printf("%d ", a[p[i]]);
        printf("%d\n", a[p[n]]);
    }
}

#include<cstdio>
#include<cstring>
using namespace std;
const int mx = 1e6 + 5;
int a[mx], b[10005], c[10005];
bool vis[mx];
int main()
{
    int n, i, j, pos, x, sum;
    long long ans;
    while (scanf("%d", &n) != EOF)
    {
        memset(vis, false, sizeof(vis));
        for (i = 0; i <= n; i++)scanf("%d", &c[i]);
        ans = 0;
        for (i = n; i >= 0; i--)
        {
            if (vis[i])continue;
            x = i, pos = 0;
            while (x)
            {
                b[pos++] = x & 1;
                x = x >> 1;
            }
            //        for(j=0; j<pos; j++)
            //            printf("%d\n",b[j]);
            sum = 0;
            for (j = 0; j < pos; j++)
            {
                if (b[j] == 0)sum += (1 << j);
            }
            vis[sum] = vis[i] = true;
            a[sum] = i;
            a[i] = sum;
            ans += ((sum ^ i) * 2);
            //printf("cp >> %d %d %d\n",ans,sum,i);
        }
        printf("%I64d\n", ans);
        printf("%d", a[c[0]]);
        for (i = 1; i <= n; i++)
            printf(" %d", a[c[i]]);
        printf("\n");
    }
}