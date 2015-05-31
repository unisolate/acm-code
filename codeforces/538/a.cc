#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; i + j <= s.size(); ++j) {
            // cout << s.substr(0, j - 1) << " " << s.substr(i + j,
                    // s.size() - i - j) << endl;
            if (s.substr(0, j - 1) + s.substr(i + j, s.size() - i - j)
                    == "CODEFORCES") {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}