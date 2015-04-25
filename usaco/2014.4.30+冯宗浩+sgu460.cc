/*
30.04.14 18:21	15 ms	62 kb
根据单词结尾，修改单词为正确的复数形式。
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char p[30];
        cin >> p;
        int x = strlen(p) - 1;
        if ((p[x - 1] == 'c' && p[x] == 'h') || p[x] == 'x' || p[x] == 's' || p[x] == 'o')
        {
            p[x + 1] = 'e';
            p[x + 2] = 's';
            x += 2;
        }
        else if (p[x - 1] == 'f' && p[x] == 'e')
        {
            p[x - 1] = 'v';
            p[x] = 'e';
            p[x + 1] = 's';
            x++;
        }
        else if (p[x] == 'f')
        {
            p[x] = 'v';
            p[x + 1] = 'e';
            p[x + 2] = 's';
            x += 2;
        }
        else if (p[x] == 'y')
        {
            p[x] = 'i';
            p[x + 1] = 'e';
            p[x + 2] = 's';
            x += 2;
        }
        else
        {
            p[x + 1] = 's';
            x++;
        }
        for (int i = 0; i <= x; ++i)
            cout << p[i];
        cout << endl;
    }
    return 0;
}