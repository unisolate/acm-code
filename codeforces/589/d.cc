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
#define MX 1024
using namespace std;
int t[MX], s[MX], f[MX], a[MX];
bool d[MX];
const double eps = 1e-8;
int dblcmp(double d) {
    if (fabs(d) < eps)
        return 0;
    return d > eps ? 1 : -1;
}
bool ok(int x, int y) {
    if (d[x] && d[y]) {
        return ((s[x] - t[x] == s[y] - t[y]) &&
                ((t[x] <= t[y] + f[y] - s[y]) || (t[y] <= t[x] + f[x] - s[x])));
    } else if (!d[x] && !d[y]) {
        return ((s[x] + t[x] == s[y] + t[y]) &&
                ((t[x] <= t[y] + s[y] - f[y]) || (t[y] <= t[x] + s[x] - f[x])));
    } else if (d[x] && !d[y]) {
        int u = s[x] - t[x], v = s[y] + t[y];
        if (u > v) {
            return false;
        }
        double m = (double)(v - u) / 2.0;
        return (dblcmp(m - t[x]) >= 0 && dblcmp(t[x] + f[x] - s[x] - m) >= 0 &&
                dblcmp(m - t[y]) >= 0 && dblcmp(t[y] + s[y] - f[y] - m) >= 0);
    } else {
        int u = s[x] + t[x], v = s[y] - t[y];
        if (u < v) {
            return false;
        }
        double m = (double)(u - v) / 2.0;
        return (dblcmp(m - t[x]) >= 0 && dblcmp(t[x] + s[x] - f[x] - m) >= 0 &&
                dblcmp(m - t[y]) >= 0 && dblcmp(t[y] + f[y] - s[y] - m) >= 0);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", t + i, s + i, f + i);
        d[i] = (f[i] > s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ok(i, j)) {
                ++a[i];
                ++a[j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}