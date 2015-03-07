#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
string s, p, v;
map<string, pair<string, string> > mp;
void prase(string u) {
    if (mp[u].second == "") {
        v += mp[u].first;
    } else {
        prase(mp[u].first), prase(mp[u].second);
    }
}
int main() {
    int t, k, l, x, y;
    scanf("%d", &t);
    while (t--) {
        mp.clear();
        scanf("%d", &k);
        getchar();
        while (k--) {
            getline(cin, s);
            l = s.length();
            y = 0;
            for (int i = 0; i < l; ++i) {
                if (s[i] == '=') x = i;
                if (s[i] == '+') y = i;
            }
            if (y) {
                mp[s.substr(0, x - 1)] =
                    make_pair(s.substr(x + 2, y - x - 3), s.substr(y + 2, l - y - 2));
            } else {
                mp[s.substr(0, x - 1)] = make_pair(s.substr(x + 2, l - x - 2), "");
            }
        }
        cin >> s >> p;
        v = "";
        // bool f = true;
        prase(s);
        // cout << v << endl;
        l = v.length();
        int m = 0;
        for (int i = 0; i < l; ++i) {
            if (p[m] == v[i])
                ++m;
        }
        if (m == p.length())
            puts("YES");
        else puts("NO");
    }
    return 0;
}