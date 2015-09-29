#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#define ls l, m, n << 1
#define rs m + 1, r, n << 1 | 1
#define lc n << 1
#define rc n << 1 | 1
using namespace std;
const int mx = 100005;
char chr[mx];
int dp[mx];
int pos[mx];
int N, V, L, R, mi[mx << 2], add[mx << 2];
void up(int n) {
    mi[n] = min(mi[lc], mi[rc]);
}
void down(int n) {
    if (add[n] != -1) {
        add[lc] = add[rc] = add[n];
        mi[lc] = mi[rc] = add[n];
        add[n] = -1;
    }
}
void B(int l = 1, int r = N, int n = 1) {
    add[n] = -1;
    if (l == r) {
        mi[n] = mx;
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs), up(n);
}
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] = mi[n] = V;
        return;
    }
    down(n);
    int m = (l + r) >> 1;
    if (L <= m)
        U(ls);
    if (m < R)
        U(rs);
    up(n);
}
int Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        return mi[n];
    }
    down(n);
    int ans = mx, m = (l + r) >> 1;
    if (L <= m)
        ans = min(ans, Q(ls));
    if (m < R)
        ans = min(ans, Q(rs));
    return ans;
}
struct P {
    int l, r, v;
} p[mx];
bool cmp(P a, P b) {
    return a.v > b.v;
}
int main() {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    int T, k, t, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &N, &k, chr + 1);
        t = chr[0] - '0';
        memset(pos, 0, sizeof(pos));
        for (int i = 1; i <= N; i++) {
            t = chr[i] - '0';
            t = t ^ 1;
            j = i;
            while (j <= N && chr[j + 1] == t + '0') {
                t = t ^ 1;
                j++;
            }
            pos[i] = j;
            i = j;
        }
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            // cout << i << " " << pos[i] << endl;
            if (pos[i] == 0) {
                p[i].l = i + 1;
            } else {
                p[i].l = pos[i] + 1;
            }
            p[i].r = min(i + k, N);
            p[i].v = dp[i - 1] + 1;
        }
        sort(p + 1, p + N + 1, cmp);
        for (int i = 1; i <= N; ++i) {
            L = p[i].l;
            R = p[i].r;
            V = p[i].v;
            U();
            printf("%d %d %d\n", L, R, V);
        }
        L = R = N;
        // printf("%d\n", dp[N]);
        printf("%d\n", Q());
    }
    return 0;
}