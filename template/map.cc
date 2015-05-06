#include <cstdio>
#include <string>
#include <map>
using namespace std;

char s[25], a[15], b[15];
map<string, string> m;

int main()
{
    while (gets(s), s[0])
    {
        sscanf(s, "%s%s", a, b);
        m[string(b)] = string(a);
    }
    while (gets(s))
        puts(m.find(s) != m.end() ? m[s].c_str() : "eh");
    return 0;
}

#include <iostream>
#include <map>
#include <string>
using namespace std;
string str;
map<string, int> mp;
map<string, int>::iterator iter, end;
int main()
{
    int n = 0;
    while (getline(cin, str))
    {
        mp[str]++;
        ++n;
    }
    iter = mp.begin();
    end = mp.end();
    while (iter != end)
    {
        cout << iter->first;
        printf(" %.4lf\n", 100.0 * (iter->second) / (double)n);
        ++iter;

    }
}