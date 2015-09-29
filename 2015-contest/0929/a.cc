#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#define MX 128
using namespace std;
struct P {
    int x, y;
    string s;
} p[MX];
bool cmp(P a, P b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x > b.x;
}
int main() {
    // freopen("t.in", "r", stdin);
    // freopen("t.out", "w", stdout);
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i].s;
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        sort(p, p + n, cmp);
        cout << p[0].s << endl;
    }
    return 0;
}