/*
ID: unisola1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int base;
    cin >> base;
    for (int j = 1; j <= 300; ++j)
    {
        int n[30], k = 0, nn = j, num = nn * nn;
        while (num >= base)
        {
            n[k] = num % base;
            num /= base;
            ++k;
        }
        n[k] = num;
        bool flag = true;
        for (int i = 0; i <= k; ++i)
        {
            if (n[i] != n[k - i])
            {
                flag = false;
                break;
            }
        }
        if (k == 0)
            flag = true;
        if (flag)
        {
            int p[15], l = 0;
            while (nn >= base)
            {
                p[l] = nn % base;
                nn /= base;
                ++l;
            }
            p[l] = nn;
            for (int i = l; i >= 0; --i)
            {
                if (p[i] < 10)
                    cout << p[i];
                else printf("%c", p[i] - 10 + 'A');
            }
            cout << " ";
            for (int i = 0; i <= k; ++i)
            {
                if (n[i] < 10)
                    cout << n[i];
                else
                    printf("%c", n[i] - 10 + 'A');
            }
            cout << endl;
        }
    }
    return 0;
}