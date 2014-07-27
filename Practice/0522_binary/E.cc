#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;
int n, c, f;
struct calve
{
    int id, x, y;
} p[MAXN], q[MAXN];
int cmpx(struct calve a, struct calve b)
{
    return a.x < b.x;
}
int cmpy(struct calve a, struct calve b)
{
    return a.y < b.y;
}
int check(int m)
{
    int sum = p[m].y, l = 0, r = 0;
    for (int i = 0; i <= c; ++i)
        if (q[i].id < m && sum + q[i].y <= f && l < n / 2)
            sum += q[i].y, ++l;
        else if (q[i].id > m && sum + q[i].y <= f && r < n / 2)
            sum += q[i].y, ++r;
    if (l < n / 2)
        return 2;
    if (r < n / 2)
        return 1;
    return 0;
}
int main()
{
    scanf("%d%d%d", &n, &c, &f);
    for (int i = 0; i < c; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);
    sort(p, p + c, cmpx);
    for (int i = 0; i < c; ++i)
    {
        p[i].id = q[i].id = i;
        q[i].x = p[i].x;
        q[i].y = p[i].y;
    }
    sort(q, q + c, cmpy);
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += q[i].y;
    if (sum > f)
        printf("-1\n");
    else
    {
        int l = 0, r = c, m;
        while (l < r)
        {
            m = (l + r + 1) >> 1;
            if (check(m) == 1)
                r = m - 1;
            else if (check(m) == 2)
                l = m + 1;
            else l = m;
        }
        printf("%d\n", p[l].x);
    }
    return 0;
}