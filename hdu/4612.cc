#include <cstdio>
#include <cstring>
#include <queue>
#define MN 200010
#define MM 2000010
using namespace std;
struct Edge {
    int to, next;
    bool cut;
    Edge() {
    }
    Edge(int _to, int _next, bool _cut) {
        to = _to;
        next = _next;
        cut = _cut;
    }
};
Edge edge[MM];
int head[MN], tot;
int low[MN], dfn[MN], stack[MN];
int idx, top;
bool inStack[MN];
int bridge;
int belong[MN];
int graphCount;
int dep[MN];
void addEdge(int u, int v) {
    edge[tot] = Edge(v, head[u], false);
    head[u] = tot++;
}
void Tarjan(int u, int pre) {
    int v;
    low[u] = dfn[u] = ++idx;
    stack[top++] = u;
    inStack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if (pre == (i ^ 1)) {
            continue;
        }
        if (dfn[v] == 0) {
            Tarjan(v, i);
            if (low[u] > low[v]) {
                low[u] = low[v];
            }
            if (low[v] > dfn[u]) {
                bridge++;
                edge[i].cut = true;
                edge[i ^ 1].cut = true;
            }
        } else if (low[u] > dfn[v]) {
            low[u] = dfn[v];
        }
    }
    if (low[u] == dfn[u]) {
        graphCount++;
        while (1) {
            int tmp = stack[--top];
            belong[tmp] = graphCount;
            inStack[u] = false;
            if (tmp == u) {
                break;
            }
        }
    }
}
void solve(int n) {
    memset(dfn, 0, sizeof(dfn));
    memset(inStack, false, sizeof(inStack));
    idx = top = graphCount = 0;
    bridge = 0;
    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0) {
            Tarjan(i, -1);
        }
    }
}
void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}
void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = head[tmp]; i != -1; i = edge[i].next) {
            int to = edge[i].to;
            if (dep[to] == -1) {
                dep[to] = dep[tmp] + 1;
                q.push(to);
            }
        }
    }
}
int main() {
    int n, m, u, v;
    while (scanf("%d%d", &n, &m) && n + m) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        solve(n);
        int x[bridge + 1];
        int y[bridge + 1];
        int xTop = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = head[i]; j != -1; j = edge[j].next) {
                if (!edge[j].cut) {
                    continue;
                }
                x[xTop] = i;
                y[xTop++] = edge[j].to;
                edge[j].cut = false;
                edge[j ^ 1].cut = false;
            }
        }
        init();
        for (int i = 0; i < bridge; ++i) {
            addEdge(belong[x[i]], belong[y[i]]);
            addEdge(belong[y[i]], belong[x[i]]);
        }
        memset(dep, -1, sizeof(dep));
        dep[belong[1]] = 0;
        bfs(belong[1]);
        int max = 0;
        int idx = 1;
        for (int i = 1; i <= graphCount; ++i) {
            if (dep[i] > max) {
                max = dep[i];
                idx = i;
            }
        }
        memset(dep, -1, sizeof(dep));
        dep[idx] = 0;
        bfs(idx);
        max = 0;
        for (int i = 1; i <= graphCount; ++i) {
            if (dep[i] > max) {
                max = dep[i];
            }
        }
        printf("%d\n", bridge - max);
    }
    return 0;
}