#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define ls l, m, n << 1          // lson
#define rs m + 1, r, n << 1 | 1  // rson
#define lc n << 1                // lchild
#define rc n << 1 | 1            // rchild
#define MX 100010
using namespace std;
typedef long long ll;
int N, X;
ll M, V, sum[MX << 2];
void up(int n) {
    sum[n] = (sum[lc] * sum[rc]) % M;
}
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        sum[n] = 1;
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs), up(n);
}
void U(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        sum[n] = V;
        return;
    }
    int m = (l + r) >> 1;
    if (X <= m)
        U(ls);
    else
        U(rs);
    up(n);
}
int main() {
    int t, o, c = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &N, &M);
        B();
        printf("Case #%d:\n", ++c);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &o);
            if (o == 1) {
                X = i;
                scanf("%lld", &V);
            } else {
                scanf("%d", &X);
                V = 1;
            }
            U();
            printf("%lld\n", sum[1]);
        }
    }
    return 0;
}