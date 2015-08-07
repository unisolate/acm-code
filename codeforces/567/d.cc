#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int> > v;
vector<pair<int, int> >::iterator r, t;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}
int main() {
    int n, k, a, m, x, ans = -1;
    scanf("%d%d%d%d", &n, &k, &a, &m);
    v.push_back(make_pair(1, n));
    int u = n / a;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &x);
        if (ans == -1) {
            pair<int, int> p = make_pair(x, 0);
            r = lower_bound(v.begin(), v.end(), p, cmp);
            t = v.end(); --t;
            if (r == v.end() || r != t) {
                --r;
            }
            u -= (r->second) / a;
            v.insert(r + 1, make_pair(x + 1, r->second - 1 - (x - r->first)));
            r->second = x - r->first;
            printf("%d\n",r->second);
            u += (r->second) / a;
            ++r;
            u += (r->second) / a;
            if (u < k) ans = i;

            for (t=v.begin();t!=v.end();++t) {
                printf("<%d %d> ", t->first, t->second);
            }
            puts("");
        }
    }
    printf("%d\n", ans);
    return 0;
}