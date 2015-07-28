#include <cstdio>
#include <algorithm>
#include <cmath>
#define mx 1000005
using namespace std;
bool prime[mx];
int num[mx], cnt[mx][10];
void init() {
    for (int i = 2; i < mx; i++) {
        if (!prime[i]) {
            for (int j = i; j < mx; j += i) {
                num[j]++;
                prime[j] = true;
            }
        }
    }
    for (int i = 2; i < mx; i++) {
        for (int j = 1; j < 10; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][num[i]]++;
    }
}
int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int have[10];
        for (int i = 1; i < 10; ++i)
            have[i] = cnt[r][i] - cnt[l - 1][i];
        int ans = 0;
        for (int i = 1; i < 10; ++i) {
            if (have[i] > 0) {
                if (have[i] > 1)
                    ans = max(ans, i);
                for (int j = i + 1; j < 10; ++j)
                    if (have[j] > 0)
                        ans = max(ans, __gcd(i, j));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}