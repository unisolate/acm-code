#include <cstdio>
#include <vector>
#include <queue>
#define MX 5555
#define INF (int)1e9
using namespace std;
struct edge
{
    int to, cost;
};
typedef pair<int, int> P;
int dist[MX], dist2[MX];
vector<edge> g[MX];
int main()
{
    int n, r, s, t, c;
    while (~scanf("%d%d", &n, &r))
    {
        for (int i = 0; i <= n; i++)
            g[i].clear();
        while (r--)
        {
            scanf("%d%d%d", &s, &t, &c);
            // edge e1, e2;
            // e1.to = t-1, e2.cost = c;
            // g[s-1].push_back(e1);
            // e2.to = s-1, e2.cost = c;
            // g[t-1].push_back(e2);
            edge e1 = {s - 1, c};
            g[t - 1].push_back(e1);
            edge e2 = {t - 1, c};
            g[s - 1].push_back(e2);
        }
        priority_queue<P, vector<P>, greater<P> > q;
        fill(dist, dist + n, INF);
        fill(dist2, dist2 + n, INF);
        dist[0] = 0;
        q.push(P(0, 0));
        while (!q.empty())
        {
            P p = q.top();
            q.pop();
            int v = p.second, d = p.first;
            if (dist2[v] < d)
                continue;
            for (int i = 0; i < g[v].size(); ++i)
            {
                edge &e = g[v][i];
                int d2 = d + e.cost;
                if (dist[e.to] > d2)
                    swap(dist[e.to], d2), q.push(P(dist[e.to], e.to));
                if (dist2[e.to] > d2 && dist[e.to] < d2)
                    dist2[e.to] = d2, q.push(P(dist2[e.to], e.to));
            }
        }
        printf("%d\n", dist2[n - 1]);
    }
    return 0;
}