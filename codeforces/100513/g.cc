#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll a[200020];
int main() {
    int n, k;
    ll tmp, ans;
    scanf("%d%d", &n, &k);
    ll mi = 0;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
        mi = min(mi, a[i]);
    }
    tmp = 0;
    for (int i = 1; i < k; i++) {
        tmp += a[i];
    }
    ans = 0;
    for (int i = k; i <= n; i++) {
        tmp = tmp + a[i] - a[i - k];
        int pos = i;
        while (tmp >= 0) {
            if (a[pos] - tmp - 1 < mi) {
                ans += a[pos] - mi;
                tmp -= a[pos] - mi;
                a[pos] = mi;
            } else {
                ans += tmp + 1;
                a[pos] -= tmp + 1;
                tmp -= tmp + 1;
            }
            --pos;
        }
        // if (tmp >= 0) {
        //     ans += tmp + 1;
        //     for (int j = i; j >= i - k + 1; j--) {
        //         if (a[j] - tmp - 1 < mi) {
        //             a[j] = mi;
        //             tmp -= a[j] - mi;
        //         } else {
        //             a[j] = a[j] - tmp - 1;
        //             tmp = -1;
        //             break;
        //         }
        //     }
        // }
    }
    printf("%I64d\n", ans);
    for (int i = 1; i <= n; i++)
        printf("%I64d ", a[i]);
    return 0;
}
/*
5 4
3 -3 -1 1 2
8 3
2 1 -3 -2 4 -3 0 2
4 2
-2 1 -2 1
3 3
-5 6 10
*/