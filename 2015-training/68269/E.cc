#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<string, int> p;
int main() {
    string s;
    int k, l;
    priority_queue<p, vector<p>, greater<p> > q;
    cin >> s >> k;
    l = s.length();
    if ((long long)l * (l + 1) / 2 < k) cout << "No such line.";
    else {
        for (int i = 0; i < l; ++i)
            q.push(make_pair(string(1, s[i]), i));
        while (k--) {
            p t = q.top();
            if (!k)
                cout << t.first;
            else {
                q.pop();
                if (t.second + 1 < l)
                    t.first += s[++t.second], q.push(t);
            }
        }
    }
    return 0;
}