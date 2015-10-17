#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define MX 128
using namespace std;
struct P {
    int a, b, i;
    bool operator<(const P &x) const {
        if (b == x.b) {
            return a < x.a;
        }
        return b > x.b;
    }
} p[MX];
int n, v[MX];
priority_queue<P> pq;
bool cmp(P x, P y) {
    if (x.a == y.a) {
        return x.b < y.b;
    }
    return x.a < y.a;
}
bool ok(int t) {
    while (!pq.empty()) {
        pq.pop();
    }
    memset(v, 0, sizeof(v));
    int pre = -1;
    for (int i = 1; i <= n; ++i) {
        // printf("#%d\n", i);
        while (!pq.empty() && pq.top().b <= p[i].a) {
            if (v[pq.top().i] < t) {
                if (pq.top().b - pre > t - v[pq.top().i]) {
                    v[pq.top().i] += t - v[pq.top().i];
                    // printf("##%d %d\n", pq.top().i, t);
                    pre += t - v[pq.top().i];
                } else {
                    v[pq.top().i] += pq.top().b - pre;
                    // printf("##%d %d\n", pq.top().i, rem);
                    pre = pq.top().b;
                }
            }
            // pre = pq.top().b;
            pq.pop();
        }
        if (!pq.empty() && pq.top().b >= p[i].b) {
            if (v[pq.top().i] < t) {
                if (p[i].a - pre > t - v[pq.top().i]) {
                    v[pq.top().i] += t - v[pq.top().i];
                    // printf("###%d %d\n", pq.top().i, t);
                    pre += t - v[pq.top().i];
                } else {
                    v[pq.top().i] += p[i].a - pre;
                    // printf("###%d %d\n", pq.top().i, rem);
                    pre = p[i].a;
                }
            }
        }
        if (pq.empty()) {
            pre = p[i].a;
        }
        pq.push(p[i]);
    }
    while (!pq.empty()) {
        if (v[pq.top().i] < t) {
            if (pq.top().b - pre > t - v[pq.top().i]) {
                v[pq.top().i] += t - v[pq.top().i];
                // printf("##%d %d\n", pq.top().i, t);
                pre += t - v[pq.top().i];
            } else {
                v[pq.top().i] += pq.top().b - pre;
                // printf("##%d %d\n", pq.top().i, rem);
                pre = pq.top().b;
            }
        }
        // pre = pq.top().b;
        pq.pop();
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] < t) {
            return false;
        }
    }
    return true;
}
void solve(int l, int r) {
    int m;
    while (l + 1 < r) {
        m = (l + r) >> 1;
        ok(m) ? l = m : r = m;
    }
    printf("%d\n", l * n);
    // ok(1);
}
int main() {
    int l = 10005;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].a, &p[i].b);
        p[i].i = i;
        l = min(l, p[i].b - p[i].a);
    }
    sort(p + 1, p + n + 1, cmp);
    solve(0, l + 1);
    return 0;
}