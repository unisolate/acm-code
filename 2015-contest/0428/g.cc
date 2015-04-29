#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
int po(int n, int b) {
    if (b == 0) return 1;
    int r = n;
    for (int i = 1; i < b; ++i)
        r *= n;
    return r;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        string s;
        cin >> s;
        s += "+";
        int ans = 0, a = 0, b = 0, p = 0;
        bool f = false, k = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'X') {
                k = true;
                if (i == 0 || s[i - 1] == '+')
                    a = 1;
                else if (s[i - 1] == '-')
                    a = -1;
                else
                    a = atoi(s.substr(p, i - p).c_str());
                if (s[i + 1] == '^')
                    p = i + 2;
                else f = true;
            } else if (i && (s[i] == '+' || s[i] == '-')) {
                if (f)
                    b = 1;
                else b = atoi(s.substr(p, i - p).c_str());
                if (!k) {
                    b = 0;
                    a = atoi(s.substr(p, i - p).c_str());
                }
                // printf("#%d %d\n", a, b);
                ans += a * po(n, b);
                p = i;
                f = k = false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}