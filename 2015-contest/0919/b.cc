#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL A, B, n, mod;
LL A1, A2, A3;
struct matrix {
    LL m[3][3];
};
matrix multiple(matrix a, matrix b) {
    matrix ans;
    LL res;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            ans.m[i][j] = 0;
            res = 0;
            for (int k = 0; k < 3; k++) {
                res += (a.m[i][k] * b.m[k][j]) % mod;
            }
            ans.m[i][j] = res;
        }
    return ans;
}
LL solve() {
    matrix a, b;
    a.m[0][0] = a.m[1][1] = a.m[2][2] = 1;
    a.m[0][1] = a.m[0][2] = a.m[1][0] = a.m[1][2] = a.m[2][0] = a.m[2][2] = 0;
    b.m[0][0] = 0;
    b.m[0][1] = 1;
    b.m[0][2] = 0;
    b.m[1][0] = 0;
    b.m[1][1] = 0;
    b.m[1][2] = 1;
    b.m[2][0] = 0;
    b.m[2][1] = -1;
    b.m[2][2] = 10;
    n--;
    while (n) {
        if (n % 2)
            a = multiple(a, b);
        b = multiple(b, b);
        n /= 2;
    }
    return ((a.m[0][0] * A1) % mod + (a.m[0][1] * A2) % mod +
            (a.m[0][2] * A3) % mod) %
           mod;
}
int main() {
    int t, cas = 0;
    LL x;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &x, &mod);
        A = 5;
        B = 24;
        A1 = 2 * A;
        A2 = (A * A + B) * 2;
        A3 = 6 * A * B + 2 * A * A * A;
        LL y = 2, ans = 1;
        while (x > 0) {
            if ((x & 1) == 1) {
                ans = (ans * y) % (mod + 1);
            }
            y = (y * y) % (mod + 1);
            x = x >> 1;
        }

        x = (ans + 1) % (mod + 1);
        n = x;
        printf("Case #%d: %lld\n", ++cas, (solve() - 1 + mod) % mod);
    }
    return 0;
}