#include <cstdio>
const int maxn = 1000010;
using namespace std;
int point[maxn * 2];
int operators(int op, int opn, int num) {
    if (op == 1)   return opn & num;
    if (op == 2)   return opn | num;
    if (op == 3)   return opn ^ num;
}
int build (int o, int L, int R) {
    point[o] = -1;
    if (L == R) {
        //printf("%d %d\n",L,R);
        scanf("%d", &point[o]);
    } else {
        int M = L + (R - L) / 2;
        build(o * 2, L, M);
        build(o * 2 + 1, M + 1, R);
        if (point[o * 2] != -1 && point[o * 2] == point[o * 2 + 1]) {
            point[o] = point[o * 2];
        }
    }
    return 0;
}
int update(int o, int L, int R, int ql, int qr, int op, int opn) {
    int M = L + (R - L) / 2;
    if (ql <= L && qr >= R
            && point[o] >= 0) point[o] = operators(op, opn, point[o]);
    else {
        if (L == R) return 0;
        if (point[o] >= 0) {
            point[o * 2 + 1] = point[o * 2] = point[o];
            point[o] = -1;
        }
        if (ql <= M)  update(o * 2, L, M, ql, qr, op, opn);
        if (qr > M)   update(o * 2 + 1, M + 1, R, ql, qr, op, opn);
        if (point[o * 2] != -1 && point[o * 2] == point[o * 2 + 1]) {
            point[o] = point[o * 2];
        } else point[o] = -1;
    }
    return 0;
}
long long  sum;
int query(int o, int L, int R, int ql, int qr) {
    if (ql <= L && qr >= R && point[o] >= 0) sum += point[o] * (R - L + 1);
    else {
        int M = L + (R - L) / 2;
        if (point[o] >= 0) {
            point[o * 2 + 1] = point[o * 2] = point[o];
            point[o] = -1;
        }
        if (ql <= M) query(o * 2, L, M, ql, qr);
        if (qr > M)  query(o * 2 + 1, M + 1, R, ql, qr);
        if (point[o * 2] != -1 && point[o * 2] == point[o * 2 + 1]) {
            point[o] = point[o * 2];
        } else point[o] = -1;
    }
    return 0;
}
int main () {
    int n, m, T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        build(1, 1, n);
        char sss[5];
        for (int i = 0; i < m; i++) {
            scanf("%s", sss);
            if (sss[0] == 'S') {
                int a, b;
                scanf("%d%d", &a, &b); sum = 0;
                query(1, 1, n, a + 1, b + 1);
                printf("%I64d\n", sum);
            }
            if (sss[0] == 'X') {
                int opnn, a, b;
                scanf("%d%d%d", &opnn, &a, &b);
                update(1, 1, n, a + 1, b + 1, 3, opnn);
            }
            if (sss[0] == 'O') {
                int opnn, a, b;
                scanf("%d%d%d", &opnn, &a, &b);
                update(1, 1, n, a + 1, b + 1, 2, opnn);
            }
            if (sss[0] == 'A') {
                int opnn, a, b;
                scanf("%d%d%d", &opnn, &a, &b);
                update(1, 1, n, a + 1, b + 1, 1, opnn);
            }
            //for (int i=1;i<=8;i++) printf("%d \n",point[i]);
        }
    }
    return 0;
}