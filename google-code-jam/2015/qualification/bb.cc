#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int d, p;

int dfs(vector<int> v) {
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");

    sort(v.begin(), v.end());
    if (v.back() == 0)
        return 0;
    int x, y, k = v.size();

    for (int i = 0; i < k; ++i)
        --v[i];
    x = dfs(v);

    if (v[k - 1] > 1) {
        for (int i = 0; i < k; ++i)
            ++v[i];
        v.push_back(v[k - 1] / 2);
        v[k - 1] -= v[k];
        y = dfs(v);
    } else return x + 1;

    return 1 + min(x, y);
}

int main() {
    // freopen("B-small-attempt2.in", "r", stdin);
    // freopen("B-small-attempt2.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &d);
        vector<int> v;
        for (int i = 0; i < d; ++i) {
            scanf("%d", &p);
            v.push_back(p);
        }
        printf("Case #%d: %d\n", ++cas, dfs(v));
    }
    return 0;
}