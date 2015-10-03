#include <bits/stdc++.h>
using namespace std;
int n, k[100];
struct tak
{
    double v;
    int pos;
} p[100][100];
int cmp(struct tak a, struct tak b)
{
    return a.v > b.v;
}
bool check()
{
    bool flag[n];
    memset(flag, false, sizeof(flag));
    for (int i = 0; i < n; ++i)
    {
        if (flag[p[i][k[i]].pos])
            return true;
        else
            flag[p[i][k[i]].pos] = true;
    }
    return false;
}
double bfs()
{
    double ans = -1;
    queue<int []> q;
    int x[20];
    int *y=x;
    memset(x, 0, sizeof(x));
    q.push();
    while (!q.empty())
    {
        int z[n] = q.front();
        q.pop();
        for (int i = 0; i < n; ++i)
            k[i] += z[i];
        if (check())
        {
            // printf("%d\n",z);
            for (int i = 0; i < n; ++i)
            {
                if (k[i] == n - 1)
                    continue;
                ++z[i];
                q.push(z);
                --z[i];
            }
        }
        else
        {
            ans = 1;
            for (int i = 0; i < n; ++i)
                ans *= (p[i][k[i]].v) / 100;
            return ans;
        }
        // --k[z];
    }
    return ans;
}
int main()
{
    double ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            scanf("%lf", &p[i][j].v);
            p[i][j].pos = j;
        }
    for (int i = 0; i < n; ++i)
        sort(p[i], p[i] + n, cmp);
    printf("%.6lf\n", bfs() * 100);
    return 0;
}