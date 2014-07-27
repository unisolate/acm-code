#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#define MAXN 10010
using namespace std;
map<string, int> p;
map<string, int>::iterator iter, end;
int main()
{
    int n, m;
    string name;
    cin >> n;
    getchar();
    for (int i = 1; i <= n; ++i)
    {
        //gets(p[i].name);
        getline(cin, name);
        p[name] = 0;
        //cout << p[i].name << endl;
    }
    //getchar();
    cin >> m;
    while (m--)
    {
        string tem;
        int temp, lm;
        for (int i = 1; i <= n; ++i)
        {
            cin >> temp;
            //gets(tem);
            getchar();
            getline(cin, tem);
            //cout << tem << endl;
            p[tem] += temp;
        }
        iter = p.begin();
        end = p.end();
        int pos = 1;
        lm = p["Li Ming"];
        while (iter != end)
        {
            if (lm < iter->second)
                pos++;
            iter++;
        }
        cout << pos << endl;
    }
    return 0;
}