
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MX 100010

using namespace std;

struct P {
    int i, v, u;
} p[MX];

struct Q {
    int i, l, r, k, v;
} q[MX];

int c[MX];

bool pcmpv(P a, P b) {
    return a.v < b.v;
}

bool pcmpi(P a, P b) {
    return a.i < b.i;
}

bool qcmpl(Q a, Q b) {
    return a.l < b.l;
}

bool qcmpi(Q a, Q b) {
    return a.i < b.i;
}

void U(int x, int v) {
    if (x == 0) {
        return;
    }
    for (; x < MX; x += (x & -x)) {
        c[x] += v;
    }
}

int Q(int x) {
    if (x == 0) {
        return 0;
    }
    int r = 0;
    for (; x > 0; x -= (x & -x)) {
        r += c[x];
    }
    return r;
}

int lb(int l, int r, int k) {
    int cnt = r - l, it, step;
    while (cnt > 0) {
        step = cnt / 2;
        it = l + step;
        if (Q(it) < k) {
            l = ++it;
            cnt -= step + 1;
        } else {
            cnt = step;
        }
    }
    return l;
}

int bs(int l, int r, int k) {
    while (l < r) {
        int m = (l + r) >> 1;
        if (p[m].u == k)
            return p[m].v;
        if (p[m].u < k)
            l = m + 1;
        else
            r = m;
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i].v);
        p[i].i = i;
    }

    sort(p + 1, p + n + 1, pcmpv);
    for (int i = 1; i <= n; ++i) {
        p[i].u = i;
    }
    sort(p + 1, p + n + 1, pcmpi);

    for (int i = 1; i <= m; ++i) {
        q[i].i = i;
        scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
    }

    sort(q + 1, q + m + 1, qcmpl);
    for (int i = 1; i <= m; ++i) {
        for (int j = q[i - 1].l; j <= min(q[i - 1].r, q[i].l - 1); ++j) {
            U(p[j].u, -1);
        }
        for (int j = max(q[i - 1].r + 1, q[i].l); j <= q[i].r; ++j) {
            U(p[j].u, 1);
        }
        q[i].v = lb(1, MX, q[i].k);
        // printf("#%d\n", q[i].v);
    }
    sort(q + 1, q + m + 1, qcmpi);

    sort(p + 1, p + n + 1, pcmpv);
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", bs(1, n + 1, q[i].v));
    }
    return 0;
}