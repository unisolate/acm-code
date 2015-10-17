#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <cstdlib>
using namespace std;
map<string, vector<string> > mp;
map<string, vector<string> >::iterator it;
vector<string>::iterator i;
string::iterator iter;
int main() {
    mp.clear();
    int n;
    scanf("%d", &n);
    string s, t;
    while (n--) {
        cin >> s;
        t = s;
        for (iter = s.begin(); iter != s.end(); ++iter) {
            if (isupper(*iter)) {
                *iter = tolower(*iter);
            }
        }
        if (s.size() >= 10 && s.substr(s.size() - 10, 10) == "@bmail.com") {
            // cout << "#" << s.substr(s.size() - 10, 10) << " "
            //      << s.substr(s.size() - 10, 10).size() << endl;

            for (iter = s.begin(); iter != s.end();) {
                if (*iter == '@') {
                    break;
                }
                if (*iter == '.') {
                    s.erase(iter);
                } else {
                    ++iter;
                }
            }

            // while (s.find('.') != string::npos) {
            //     s.erase(s.find('.'), 1);
            // }

            int x = -1, y = -1;
            for (iter = s.begin(); iter != s.end(); ++iter) {
                if (x == -1 && *iter == '+') {
                    x = iter - s.begin();
                }
                if (*iter == '@') {
                    y = iter - s.begin();
                }
            }
            if (x != -1 && y != -1) {
                // cout << "##" << s.substr(x, y - x) << " "
                //      << s.substr(x, y - x).size() << endl;

                s.erase(x, y - x);
            }
        }
        mp[s].push_back(t);
        // cout << "###" << s << " " << t << endl;
    }
    printf("%lu\n", mp.size());
    for (it = mp.begin(); it != mp.end(); ++it) {
        printf("%lu", (it->second.size()));
        for (i = it->second.begin(); i != it->second.end(); ++i) {
            cout << " " << *i;
        }
        puts("");
    }
    return 0;
}