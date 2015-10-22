/* 14476 KB 1204 ms */
#include <cstdio>
#include <algorithm>
#define MX 100010
using namespace std;
int p[MX], s[20][MX], sum[20][MX];
void B(int l, int r, int n = 0) {
    int m = (l + r) >> 1;
    int L = l, R = m + 1;
    int x = p[m];
    sum[n][l] = 0;
    int cnt = m - l + 1;
    for (int i = l; i <= r; ++i) {
        if (s[n][i] < x) {
            --cnt;
        }
    }
    for (int i = l; i <= r; ++i) {
        if (i > l) {
            sum[n][i] = sum[n][i - 1];
        }
        if (L <= m && (s[n][i] < x || (s[n][i] == x && cnt-- > 0))) {
            s[n + 1][L++] = s[n][i];
            sum[n][i]++;
        } else {
            s[n + 1][R++] = s[n][i];
        }
    }
    if (l < m) {
        B(l, m, n + 1);
    }
    if (m + 1 < r) {
        B(m + 1, r, n + 1);
    }
}
int Q(int L, int R, int k, int l, int r, int n = 0) {
    if (l == r) {
        return s[n][l];
    }
    int m = (l + r) >> 1;
    int v = 0;
    if (L > l) {
        v = sum[n][L - 1];
    }
    int t = sum[n][R] - v;
    if (t >= k) {
        return Q(l + v, l + sum[n][R] - 1, k, l, m, n + 1);
    }
    return Q(m + 1 + L - l - v, m + 1 + R - l - sum[n][R], k - t, m + 1, r,
             n + 1);
}
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", p + i);
        }
        for (int i = 0; i < 20; ++i) {
            sum[i][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            s[0][i] = p[i];
        }
        sort(p + 1, p + n + 1);
        B(1, n);
        while (m--) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", Q(l, r, k, 1, n));
        }
    }
    return 0;
}