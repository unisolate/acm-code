#include <cstdio>
#include <map>
using namespace std;
int main() {
    int n, v;
    while (~scanf("%d", &n)) {
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            scanf("%d", &v);
            mp[v]++;
            if (mp[v] == 2)
                ans = v;
        }
        printf("%d\n", ans);
    }
    return 0;
}