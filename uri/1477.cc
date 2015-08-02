#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 100001
#define ls l,m,n<<1     // lson
#define rs m+1,r,n<<1|1 // rson
#define lc n<<1         // lchild
#define rc n<<1|1       // rchild
using namespace std;
int N, L, R, m, tl, tr;
int num[MX], add[MX << 2], sum[MX << 2][3];
void up(int n) {
    for (int i = 0; i < 3; ++i)
        sum[n][i] = sum[lc][i] + sum[rc][i];
}
void down(int n) {
    if (add[n]) {
        add[lc] += add[n];
        add[rc] += add[n];
        for (int i = 0; i < add[n] % 3; ++i) {
            tl = sum[lc][2];
            tr = sum[rc][2];
            sum[lc][2] = sum[lc][1];
            sum[rc][2] = sum[rc][1];
            sum[lc][1] = sum[lc][0];
            sum[rc][1] = sum[rc][0];
            sum[lc][0] = tl;
            sum[rc][0] = tr;
        }
        // sum[lc] += add[n] * (m - (m >> 1));
        // sum[rc] += add[n] * (m >> 1);
        add[n] = 0;
    }
}
void B(int l = 1, int r = N, int n = 1) {
    add[n] = 0;
    if (l == r) {
        num[l] = sum[n][1] = sum[n][2] = 0;
        sum[n][0] = 1;
        // add[n] = 0;
        // for (int i = 0; i < 3; ++i)
        //     sum[n][i] = ((num[l] % 3) == i ? 1 : 0);
        return;
    }
    // down(n);
    int m = (l + r) >> 1;
    B(ls), B(rs), up(n);
}
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        ++add[n];
        tl = sum[n][2];
        sum[n][2] = sum[n][1];
        sum[n][1] = sum[n][0];
        sum[n][0] = tl;
        // sum[n] += V * (r - l + 1);
        return;
    }
    down(n);
    int m = (l + r) >> 1;
    if (L <= m) U(ls);
    if (m < R) U(rs);
    up(n);
}
int Q(int k, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        return sum[n][k];
    }
    down(n);
    int ans = 0, m = (l + r) >> 1;
    if (L <= m) ans += Q(k, ls);
    if (m < R) ans += Q(k, rs);
    return ans;
}
int main() {
    char s[9];
    while (~scanf("%d%d", &N, &m)) {
        // memset(num, 0, sizeof(num));
        // memset(add, 0, sizeof(add));
        B();
        while (m--) {
            scanf("%s%d%d", s, &L, &R);
            if (s[0] == 'M') {
                U();
            } else {
                // B();
                printf("%d %d %d\n", Q(0), Q(1), Q(2));
            }
        }
        puts("");
    }
    return 0;
}