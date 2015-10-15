/* 17832 KB, 6157 ms */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define MX 100010
#define ls l, m, n << 1          // lson
#define rs m + 1, r, n << 1 | 1  // rson
#define lc n << 1                // lchild
#define rc n << 1 | 1            // rchild
using namespace std;

int num[MX];
vector<int> sum[MX << 2];
int N, L, R, X, V;

void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        scanf("%d", &num[l]);
        sum[n].push_back(num[l]);
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs);
    sum[n].resize(r - l + 1);
    merge(sum[lc].begin(), sum[lc].end(), sum[rc].begin(), sum[rc].end(),
          sum[n].begin());
}

int Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        return upper_bound(sum[n].begin(), sum[n].end(), V) - sum[n].begin();
    }
    int ans = 0, m = (l + r) >> 1;
    if (L <= m) {
        ans += Q(ls);
    }
    if (m < R) {
        ans += Q(rs);
    }
    return ans;
}

int S() {
    // int l = 1, r = N, p, a = 1;
    // while (l <= r) {
    //     p = (l + r) >> 1;
    //     V = num[p];
    //     if (Q() < X) {
    //         l = p + 1;
    //     } else {
    //         a = p;
    //         r = p - 1;
    //     }
    // }
    // return a;

    int l = 1, r = N + 1, cnt = r - l, it, step;
    while (cnt > 0) {
        step = cnt / 2;
        it = l + step;
        V = num[it];
        if (Q() < X) {
            l = ++it;
            cnt -= step + 1;
        } else {
            cnt = step;
        }
    }
    return l;
}

int main() {
    int m;
    while (~scanf("%d%d", &N, &m)) {
        B();
        sort(num + 1, num + N + 1);
        while (m--) {
            scanf("%d%d%d", &L, &R, &X);
            printf("%d\n", num[S()]);
        }
    }
    return 0;
}