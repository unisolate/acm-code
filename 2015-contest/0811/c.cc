#include <cstdio>
#include <algorithm>
#define MX 222222
using namespace std;
int n, l[MX], p[MX];
void palindrome() { //l[i] means the max palindrome length centered i/2
    for (int i = 0; i < n * 2; ++i) {
        l[i] = 0;
    }
    for (int i = 0, j = 0, k; i < n * 2; i += k, j = max(j - k, 0)) {
        while (i - j >= 0 && i + j + 1 < n * 2
                && p[(i - j) / 2] == p[(i + j + 1) / 2])
            j++;
        l[i] = j;
        for (k = 1; i - k >= 0 && j - k >= 0 && l[i - k] != j - k; k++) {
            l[i + k] = min(l[i - k], j - k);
        }
    }
}
int main() {
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", p + i);
        palindrome();
        int a = 0;
        for (int i = 1; i < n * 2; i += 2) {
            int k = l[i];
            if (k > a && ((i - k > 0 && l[i - k] >= k) || (i + k < n * 2
                          && l[i + k] >= k))) {
                printf("%d %d\n", i, k);
                a = k;
            }
            // while (k > a) {
            //     if (i + k < n * 2 && l[i + k] >= k) {
            //         a = k;
            //     }
            //     k -= 2;
            // }
        }
        printf("Case #%d: %d\n", ++cas, a / 2 * 3);
    }
    return 0;
}