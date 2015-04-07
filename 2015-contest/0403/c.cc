#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MX 102400
#define INF 0x7f7f7f7f
using namespace std;

int n, x[MX], y[MX], d[MX];
bool f[MX];

int abs(int k) {
    if (k < 0) return -k;
    return k;
}

struct E {
    int num, d;
};

bool operator< (E a, E b) {
    return a.d > b.d;
}

inline int edge(int i, int j) {
    return min(abs(x[i] - x[j]), abs(y[i] - y[j]));
}

void dijkstra(int source) {
    priority_queue<E> que;
    E p;
    p.num = source;
    p.d = 0;
    que.push(p);
    d[source] = 0;
    while (!que.empty()) {
        E p = que.top();
        que.pop();
        f[p.num] = true;
        for (int i = 1; i <= n; ++i) {
            if (f[i]) continue;
            if (d[p.num] + edge(p.num, i) < d[i]) {
                d[i] = d[p.num] + edge(p.num, i);
                E q;
                q.num = i, q.d = d[i];
                que.push(q);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        d[i] = INF;
    }
    dijkstra(1);
    printf("%d\n", d[n]);
    return 0;
}