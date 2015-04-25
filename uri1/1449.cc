#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
    int t, m, n;
    scanf("%d", &t);
    while (t--)
    {
        string x, y;
        map<string, string> mp;
        scanf("%d%d", &m, &n);
        getchar();
        while (m--)
        {
            getline(cin, x);
            getline(cin, y);
            mp[x] = y;
        }
        while (n--)
        {
            getline(cin, x);
            istringstream stream(x);
            bool f = false;
            while (stream >> y)
            {
                if (f) printf(" "); else f = true;
                if (mp.count(y))
                    cout << mp[y];
                else cout << y;
            }
            putchar(10);
        }
        putchar(10);
    }
    return 0;
}