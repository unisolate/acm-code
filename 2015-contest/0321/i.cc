#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n, m, p, z, c;
    while (~scanf("%d", &n)) {
        map<string, vector<string> > mp;
        map<string, int> t;
        map<string, int>::iterator it;
        vector<string> v;
        string s, l;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            getchar();
            getline(cin, l);
            p = 0, z = l.size();
            for (int j = 0; j <= z; ++j) {
                if (l[j] == ' ' || j == z) {
                    // cout << "#" << l.substr(p, j - p + 1) << endl;
                    mp[s].push_back(l.substr(p, j - p));
                    p = j + 1;
                }
            }
            // mp[s].push_back(l.substr(p, z - p));
            // cout << "##" << mp[s].back() << endl;
        }
        scanf("%d", &m);
        getchar();
        while (m--) {
            getline(cin, l);
            p = 0, z = l.size(), c = 0;
            t.clear();
            for (int i = 0; i <= z; ++i) {
                if (l[i] == ' ' || i == z) {
                    ++c;
                    v = mp[l.substr(p, i - p)];
                    // cout << "###" << l.substr(p, i - p) << endl;
                    p = i + 1;
                    while (!v.empty()) {
                        // cout << "##" << v.back() << endl;
                        ++t[v.back()];
                        v.pop_back();
                    }
                }
            }
            // ++c;
            // v = mp[l.substr(p, z - p)];
            // while (!v.empty()) {
            //     ++t[v.back()];
            //     v.pop_back();
            // }
            // printf("#%d\n", c);
            bool f = false;
            for (it = t.begin(); it != t.end(); ++it) {
                // cout << it->first << " " << it->second << endl;
                if (it->second == c) {
                    if (f) cout << " ";
                    cout << it->first;
                    f = true;
                }
            }
            if (f)
                puts("");
            else
                puts("NO");
        }
    }
    return 0;
}