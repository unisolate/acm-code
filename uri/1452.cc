#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
map<string, int> mp[256];
bool f[256];
int main() {
    int n, m, k;
    string s;
    while (scanf("%d%d", &n, &m) && n + m) {
        for (int i = 0; i < n; ++i) {
            mp[i].clear();
            scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                cin >> s;
                mp[i][s] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            memset(f, false, sizeof(f));
            scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                cin >> s;
                for (int l = 0; l < n; ++l) {
                    if (mp[l][s]) {
                        f[l] = true;
                    }
                }
            }
            for (int i = 0; i < n; ++i)
                if (f[i]) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}