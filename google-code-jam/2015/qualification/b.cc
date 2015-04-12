#include <cstdio>
#include <algorithm>
using namespace std;
int p[1024], q[1024];
int get(int d) {
    for (int i = d - 1; i >= 0; --i)
        if (p[i] < p[d - 1])
            return p[i];
    return 0;
}
int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt.out", "w", stdout);
    int t, d, cas = 0;
    scanf("%d", &t);
    while (t--) {
        int m = 0;
        memset(q, 0, sizeof(q));
        scanf("%d", &d);
        for (int i = 0; i < d; ++i) {
            scanf("%d", &p[i]), ++q[p[i]];
            m = max(m, p[i]);
        }
        int ans = 0;
        // for (int i = 1000; i > 0; --i) {
        //     if (q[i]) {
        //         ans = min(i, q[i] + i - i / 2);
        //         break;
        //     }
        // }
        while (1) {
            sort(p, p + d);
            if (p[d - 1] <= 0)
                break;
            ++ans;
            if (q[p[d - 1]] + p[d - 1] - p[d - 1] / 2 < p[d - 1]
                    && p[d - 1] > 1 + get(d)) {
                // printf("#\n");
                --q[p[d - 1]];
                ++d;
                p[d - 1] = p[d - 2] / 2;
                p[d - 2] -= p[d - 1];
                ++q[p[d - 1]];
                ++q[p[d - 2]];
            } else {
                for (int i = 0; i < d; ++i) {
                    if (p[i] > 0) {
                        --q[p[i]];
                        --p[i];
                        ++q[p[i]];
                    }
                }
            }
        }
        // ans = min(ans, m);
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}

/*
4 -> 3

4 4 -> 4

4 4 4 -> 4

4 4 4 4 -> 4

5 5 -> 5

6 6 -> 5

6 6 6 -> 6

7 7 -> 6

8 8 -> 6

8 8 8 -> 7

8 8 8 8 -> 8

6 7 6 5 -> 7
*/