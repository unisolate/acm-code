#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define MX 1024
using namespace std;
struct A {
    int a, b;
} ans[MX];
int n, d, z;
map<string, int> m;
vector<int> v[MX];
string s[MX], u[MX];
int cmp(A a, A b) {
    if (a.b == b.b) {
        return u[a.a] < u[b.a];
    }
    return a.b > b.b;
}
void dfs(int id, int l) {
    if (l == d) {
        z += v[id].size();
        return;
    }
    for (int i = 0; i < v[id].size(); ++i) {
        dfs(v[id][i], l + 1);
    }
}
int main() {
    int t, cas = 0, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &d);
        string r;
        m.clear();
        int id = 1;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            if (m[s[i]] == 0) {
                u[id] = s[i];
                v[id].clear();
                m[s[i]] = id++;
            }
            scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                cin >> r;
                if (m[r] == 0) {
                    u[id] = r;
                    v[id].clear();
                    m[r] = id++;
                }
                v[m[s[i]]].push_back(m[r]);
            }
        }
        for (int i = 1; i < id; ++i) {
            z = 0;
            dfs(i, 1);
            ans[i].a = i;
            ans[i].b = z;
            // printf("%d\n", ans[i]);
        }
        if (cas)
            puts("");
        printf("Tree %d:\n", ++cas);
        sort(ans + 1, ans + id, cmp);
        for (int i = 1; i <= 3; ++i) {
            if (ans[i].b == 0)
                break;
            cout << u[ans[i].a];
            printf(" %d\n", ans[i].b);
        }
        k = 4;
        while (k < id && ans[k].b > 0 && ans[k].b == ans[k - 1].b) {
            cout << u[ans[k].a];
            printf(" %d\n", ans[k].b);
            ++k;
        }
    }
    return 0;
}