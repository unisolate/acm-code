#include <cstdio>
#include <cstring>
#define MX 100
using namespace std;
int a[MX], b[MX];
void cala(int x) {
    if (x <= 0) {
        memset(a, 0, sizeof(a));
    } else {
        int k = 0;
        for (int i = 0; i < 32; ++i)
            if (1 & (x >> i)) k = i;
        for (int i = 0; i <= k; ++i) {
            a[i] = a[i] + (x + 1) / (1 << (i + 1)) * (1 << i);
            if ((x + 1) % (1 << (i + 1)) - (1 << i) > 0) {
                a[i] = a[i] + (x + 1) % (1 << (i + 1)) - (1 << i);
            }
        }
    }
}
void calb(int x) {
    if (x <= 0) {
        memset(b, 0, sizeof(b));
    } else {
        int k = 0;
        for (int i = 0; i < 32; ++i)
            if (1 & (x >> i)) k = i;
        for (int i = 0; i <= k; ++i) {
            b[i] = b[i] + (x + 1) / (1 << (i + 1)) * (1 << i);
            if ((x + 1) % (1 << (i + 1)) - (1 << i) > 0) {
                b[i] = b[i] + (x + 1) % (1 << (i + 1)) - (1 << i);
            }
        }
    }
}
int main() {
    int l, r;
    while (~scanf("%d%d", &l, &r)) {
        int ans[MX];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cala(l - 1);
        calb(r);
        for (int i = 0; i < MX; ++i)
            ans[i] = b[i] - a[i];
        long long res = 0;
        for (int i = 0; i < MX - 1; ++i) {
            res = res + ans[i] / 2;
            ans[i + 1] = ans[i + 1] + ans[i] / 2;
        }
        printf("%lld\n", res);
    }
    return 0;
}