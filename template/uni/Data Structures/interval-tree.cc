#include <cstdio>
#include <cstring>
#include <algorithm>

#define MX 1024000
#define ls l,m,n<<1     // lson
#define rs m+1,r,n<<1|1 // rson
#define lc n<<1         // lchild
#define rc n<<1|1       // rchild
using namespace std;

int num[MX], sum[MX << 2], ma[MX << 2], mi[MX << 2], add[MX << 2];
int N, L, R, V, X;

void up(int n) {
    sum[n] = sum[lc] + sum[rc];
    ma[n] = max(ma[lc], ma[rc]);
    mi[n] = min(mi[lc], mi[rc]);
}

void down(int n, int m) {
    if (add[n]) {
        add[lc] += add[n];
        add[rc] += add[n];
        sum[lc] += add[n] * (m - (m >> 1));
        sum[rc] += add[n] * (m >> 1);
        add[n] = 0;
    }
}

void B(int l = 1, int r = N, int n = 1) {
    add[n] = 0;
    if (l == r) {
        scanf("%d", &num[l]);
        sum[n] = ma[n] = mi[n] = num[l];
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs), up(n);
}

// 单点更新 X 为 V
void U(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        sum[n] = ma[n] = mi[n] = num[l] = V; // 赋值或增加
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (X <= m) U(ls);
    else U(rs);
    up(n);
}

// 区间更新 [L,R] 为 V
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] += V, sum[n] += V * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(ls);
    if (m < R) U(rs);
    up(n);
}

// 查询区间 [L,R]
int Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        return sum[n];
    }
    down(n, r - l + 1);
    int ans = 0, m = (l + r) >> 1;
    if (L <= m) ans += Q(ls);
    // ans = max(ans, Q(ls));
    if (m < R) ans += Q(rs);
    // ans = max(ans, Q(rs));
    return ans;
}