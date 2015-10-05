#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <iterator>
#include <map>
using namespace std;
string s;
map<string, string> mp;
map<string, bool> am;
int main() {
    while (getline(cin, s)) {
        for (string::iterator i = s.begin(); i != s.end();) {
            if (isalpha(*i)) {
                string::iterator j = i;
                while (j != s.end() && (isalpha(*j) || isdigit(*j))) {
                    ++j;
                }
                string t = s.substr(i - s.begin(), distance(i, j));
                bool w = true;
                for (string::iterator it = t.begin(); it != t.end(); ++it) {
                    if (isdigit(*it)) {
                        w = false;
                    }
                }
                if (mp.find(t) != mp.end() && !am[t]) {
                    s.erase(i, j);
                    s.insert(i - s.begin(), mp[t]);
                    // cout << endl << '#' << t << endl;
                    cout << mp[t];
                } else if (t.length() > 3 && w) {
                    int k = t.length() - 2;

                    string x = t;
                    for (string::iterator it = x.begin(); it != x.end(); ++it) {
                        *it = tolower(*it);
                    }
                    string p = x.substr(0, 1);
                    if (k < 10) {
                        p.push_back(k + '0');
                    } else {
                        p.push_back((k / 10) + '0');
                        p.push_back((k % 10) + '0');
                    }
                    p.push_back(x[x.length() - 1]);
                    if (mp.find(p) != mp.end() && mp[p] != x) {
                        am[p] = true;
                    } else {
                        mp[p] = x;
                    }

                    string::iterator ite = x.begin();
                    *ite = toupper(*ite);
                    p = x.substr(0, 1);
                    if (k < 10) {
                        p.push_back(k + '0');
                    } else {
                        p.push_back((k / 10) + '0');
                        p.push_back((k % 10) + '0');
                    }
                    p.push_back(x[x.length() - 1]);
                    if (mp.find(p) != mp.end() && mp[p] != x) {
                        am[p] = true;
                    } else {
                        mp[p] = x;
                    }

                    x = t;
                    for (string::iterator it = x.begin(); it != x.end(); ++it) {
                        *it = toupper(*it);
                    }
                    p = x.substr(0, 1);
                    if (k < 10) {
                        p.push_back(k + '0');
                    } else {
                        p.push_back((k / 10) + '0');
                        p.push_back((k % 10) + '0');
                    }
                    p.push_back(x[x.length() - 1]);
                    if (mp.find(p) != mp.end() && mp[p] != x) {
                        am[p] = true;
                    } else {
                        mp[p] = x;
                    }

                    // cout << endl << "##" << p << endl;
                    cout << t;
                } else {
                    cout << t;
                }
                while (i != s.end() && (isalpha(*i) || isdigit(*i))) {
                    ++i;
                }
            } else {
                cout << *i;
                ++i;
            }
        }
        cout << endl;
    }
    return 0;
}