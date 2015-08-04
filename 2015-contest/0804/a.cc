#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
string x, y;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> x >> y;
        int a = x.length(), b = y.length(), u , v;
        m.clear();
        for (int i = 1; i <= a; ++i) {
            for (int j = 0; j + i - 1 < a; ++j) {
                m[x.substr(j, i)] = 1;
            }
        }
        u = m.size();
        m.clear();
        for (int i = 1; i <= b; ++i) {
            for (int j = 0; j + i - 1 < b; ++j) {
                m[y.substr(j, i)] = 1;
            }
        }
        v = m.size();
        printf("%d\n", u * v);
    }
    return 0;
}