#include <cstdio>
#include <algorithm>
#include <cmath>
#define MX 100010
using namespace std;
int a[MX];
struct point
{
    double x, y;
} p[MX];
int cmpx(point a, point b)
{
    return a.x < b.x;
}
int cmpy(int a, int b)
{
    return p[a].y < p[b].y;
}
double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double run(int l, int r)
{
    if (r == l + 1)
        return dist(p[l], p[r]);
    if (r == l + 2)
        return min(dist(p[l], p[r]), min(dist(p[l], p[l + 1]), dist(p[l + 1], p[r])));
    int mid = (l + r) / 2;
    double ans = min(run(l, mid), run(mid + 1, r));
    int k = 0;
    for (int i = l; i <= r; ++i)
        if (p[i].x >= p[mid].x - ans && p[i].x <= p[mid].x + ans)
            a[k++] = i;
    sort(a, a + k, cmpy);
    for (int i = 0; i < k; ++i)
        for (int j = i + 1; j < k; ++j)
        {
            if (p[a[j]].y - p[a[i]].y >= ans)
                break;
            ans = min(ans, dist(p[a[i]], p[a[j]]));
        }
    return ans;
}
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        sort(p, p + n, cmpx);
        printf("%.2lf\n", run(0, n - 1) / 2);
    }
    return 0;
}