/*
ID: unisola1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;
char name[20];
char ref[15][5];
int main()
{
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    ifstream fin ("dict.txt");
    cin >> name;
    int len = strlen(name);
    char next = 'A';
    char dic[20];
    for (int i = 2; i < 10; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ref[i][j] = next++;
            if (next == 'Q')
                next++;
        }
    }
    bool check = false;
    while (fin >> dic)
    {
        if (dic[0] > ref[name[0] - '0'][2])
            break;
        if (strlen(dic) == len)
        {
            bool flag = true;
            for (int i = 0; i < len; ++i)
            {
                if (dic[i] != ref[name[i] - '0'][0] &&
                        dic[i] != ref[name[i] - '0'][1] &&
                        dic[i] != ref[name[i] - '0'][2])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                check = true;
                cout << dic << endl;
            }
        }
    }
    if (!check)
    {
        cout << "NONE" << endl;
    }
    return 0;
}