#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
int x[999];
char o[999][9];
set<int> m;
int main() {
    int n, ans = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", o[i], &x[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (o[i][0] == '-') {
            bool f = true;
            for (int j = 0; j < i; ++j) {
                if (x[j] == x[i] && o[j][0] == '+') {
                    f = false;
                    break;
                }
            }
            if (f) {
                m.insert(x[i]);
            }
        }
    }
    ans = max(ans, (int)m.size());
    for (int i = 0; i < n; ++i) {
        if (o[i][0] == '+') {
            m.insert(x[i]);
        } else if (o[i][0] == '-') {
            m.erase(x[i]);
        }
        ans = max(ans, (int)m.size());
    }
    printf("%d\n", ans);
    return 0;
}