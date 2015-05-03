// #pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <algorithm>
#define MX 10000001
using namespace std;
typedef long long ll;
ll MOD = 4294967296LL;
// struct P {
//     ll l, r;
// } p[MX];
int n, a, b, c, d;
// int cmp(P x, P y) {
//     if (x.l == y.l)
//         return x.r < y.r;
//     return x.l < y.l;
// }
// P *lb(int value) {
//     P *it;
//     P *first = p, *last = p + n;
//     int count, step;
//     count = std::distance(first, last);

//     while (count > 0) {
//         it = first;
//         step = count / 2;
//         std::advance(it, step);
//         if (!(value < (*it).l)) {
//             first = ++it;
//             count -= step + 1;
//         } else count = step;
//     }
//     return first;
// }
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll l, r, pl, pr, sl, sr, minr = MOD + 1, maxl = 0;
        scanf("%d%lld%lld%d%d%d%d", &n, &l, &r, &a, &b, &c, &d);
        pl = maxl = l, pr = minr = r;
        if (maxl > minr)
            swap(maxl, minr);
        for (int i = 1; i < n; ++i) {
            l = (l * a + b) % MOD;
            r = (r * c + d) % MOD;
            if (l > r)
                sl = r, sr = l;
            else sl = l, sr = r;

            if (sr < minr) {
                minr = sr;
                // minp = i;
            }
            if (sl > maxl) {
                maxl = sl;
                // maxp = i;
            }
            // minl = min(minl, l);
            // minr = min(minr, r);
            // maxl = max(maxl, l);
            // maxr = max(maxr, r);
        }
        // sort(p, p + n, cmp);
        bool f = false;
        // P *x = lb(p[0].r), *y = &p[0];
        // if (x >= p + n) f = false;
        // else y = lb((*x).r);
        // if (y >= p + n) f = false;
        
        // if (pl > minr && pr < maxl)
        //     f = true;
        l = pl, r = pr;
        for (int i = 0; i < n; ++i) {
            if (l > r)
                sl = r, sr = l;
            else sl = l, sr = r;

            if (sl > minr && sr < maxl)
                f = true;

            l = (l * a + b) % MOD;
            r = (r * c + d) % MOD;
        }
        if (n < 3) f = false;
        if (f)
            puts("YES");
        else puts("NO");
    }
    return 0;
}