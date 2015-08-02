#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstring>
#include <algorithm>
#include <cstdio>
#define maxn 100010
#define maxm 400010
const int inf = 0x3f3f3f3f;
#define th(x) this->x = x
using namespace std;
typedef long long ll;
struct Nod {
    int b, next;
    int cap, flow;
    void init(int b, int cap, int next) {
        th(b); th(cap); th(next);
    }
};
struct SAP {
    int E[maxn], n;
    int h[maxn], vh[maxn], source, sink;
    Nod buf[maxm];
    int len; //资源所在
    void init(int n) {
        this->n = n;
        len = 0;
        memset(E, 255, sizeof(E));
    }
    void addCap(int i, int j, int cap) {
        buf[len].init(j, cap, E[i]);
        E[i] = len++;
        buf[len].init(i, cap, E[j]);
        E[j] = len++;
    }
    int sap(const int idx, const int maxCap) {
        if (idx == sink) return maxCap;
        int l = maxCap, d, minH = n;
        for (int i = E[idx]; i != -1; i = buf[i].next) {
            Nod &nod = buf[i];
            if (nod.cap - nod.flow > 0) {
                if (h[idx] == h[nod.b] + 1) {
                    d = sap(nod.b, min(l, nod.cap - nod.flow));
                    nod.flow += d;
                    buf[i ^ 1].flow -= d;//i^1是i的伙伴
                    l -= d;
                    if (h[source] == n || l == 0)
                        return maxCap - l;
                }
                minH = min(minH, h[nod.b] + 1);
            }
        }
        if (l == maxCap) {
            vh[h[idx]]--;
            vh[minH]++;
            if (vh[h[idx]] == 0)
                h[source] = n;
            h[idx] = minH;
        }
        return maxCap - l;
    }
    int solve(int source, int sink) {
        if (source == sink)
            return inf;
        th(source);
        th(sink); /*memset(h, 0, sizeof(h)); memset(vh, 0, sizeof(vh));*/
        bfs();
        for (int i = 0; i < len; i ++)
            buf[i].flow = 0;
        int ans = 0;
        while (h[source] != n)
            ans += sap(source, inf);
        return ans;
    }
    void bfs() {
        fill(h, h + n, n);
        int *q = vh;
        int head = 0, tail = 0;
        h[sink] = 0;
        q[tail++] = sink;
        int u;
        while (tail - head) {
            u = q[head++];
            for (int i = E[u]; i != -1; i = buf[i].next) {
                if ((i & 1) && (h[buf[i].b] == n)) {
                    h[buf[i].b] = h[u] + 1;
                    q[tail++] = buf[i].b;
                }
            }
        }
        memset(vh, 0, sizeof(vh));
        for (int i = 0; i < n; i ++)
            vh[h[i]]++;
    }
} S;
int main() {
    int t, n, m, a, b, c, l, r, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        S.init(n);
        l = r = 1;
        x = maxn, y = -maxn;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &b);
            if (a < x) {
                x = a;
                l = i + 1;
            } else if (a > y) {
                y = a;
                r = i + 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            S.addCap(a, b, c);
        }
        printf("%d\n", S.solve(l, r));
    }
    return 0;
}