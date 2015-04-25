/*
ID: unisola1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int t, m, n, k;
    map<string, int> p;
    string name, rec, list[10];
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> name;
        list[i] = name;
        p[name] = 0;
    }
    for (int i = 0; i < t; ++i)
    {
        cin >> name >> m >> n;
        if (m == 0 || n == 0)
            continue;
        p[name] -= m;
        k = m / n;
        if (m % n)
        {
            p[name] += m - n * k;
        }
        for (int j = 0; j < n; ++j)
        {
            cin >> rec;
            p[rec] += k;
        }
    }
    for (int i = 0; i < t; ++i)
    {
        cout << list[i] << " " << p[list[i]] << endl;
    }
    return 0;
}