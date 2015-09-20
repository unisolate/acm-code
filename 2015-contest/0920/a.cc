#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <complex>
const double eps = 1e-8;
#define MX 128
using namespace std;
int n, m;
double x[MX], y[MX];
int dblcmp(double d) {
    if (fabs(d) < eps)
        return 0;
    return d > eps ? 1 : -1;
}
int cnt(int v, int p) {
    int c = 0;
    for (int i = 0; i < m; ++i) {
        if (dblcmp((x[i] - x[v]) * (x[i] - x[v]) +
                   (y[i] - y[v]) * (y[i] - y[v]) - p * p) == 0)
            return -1;
        if (dblcmp((x[i] - x[v]) * (x[i] - x[v]) +
                   (y[i] - y[v]) * (y[i] - y[v]) - p * p) < 0) {
            ++c;
        }
    }
    return c;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i) {
            scanf("%lf%lf", x + i, y + i);
        }
        int ans = 3000;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = 3000, p;
            while (l <= r) {
                p = (l + r) >> 1;
                if (cnt(i, p) == n) {
                    ans = min(ans, p);
                }
                if (cnt(i, p) < n) {
                    l = p + 1;
                } else {
                    r = p - 1;
                }
            }
        }
        printf("%d\n", ans == 3000 ? -1 : ans);
    }
    return 0;
}