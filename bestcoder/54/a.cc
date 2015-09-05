#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
struct P {
    string s;
    int y;
} p[128];
int cmp(P x, P y) {
    return x.y > y.y;
}
string s;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            int a = 0;
            for (int i = s.size() - 1; i >= 0; --i) {
                if (s[i] == ' ') {
                    a = i;
                    break;
                }
            }
            // cout << s.substr(0, a) << " " << s.substr(a + 1, s.size() - a -
            // 1)
            //      << endl;
            p[i].s = s.substr(0, a);
            p[i].y = atoi((s.substr(a + 1, s.size() - a - 1)).c_str());
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; ++i) {
            cout << p[i].s << endl;
        }
    }
    return 0;
}