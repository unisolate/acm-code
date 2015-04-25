/*
ID: unisola1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctype.h>
#define MAXN 22222
using namespace std;
char buf[MAXN], s[MAXN];
int p[MAXN];
int main()
{
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    int n = 0, m = 0, maxx = 0, x, y;
    while (~scanf("%c", &buf[n]))
    {
        n++;
    }
    n = strlen(buf);
    for (int i = 0; i < n; ++i)
    {
        if (isalpha(buf[i]))
        {
            p[m] = i;
            s[m++] = toupper(buf[i]);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; i - j >= 0 && i + j < m; ++j)
        {
            if (s[i - j] != s[i + j])
                break;
            if (j * 2 + 1 > maxx)
            {
                maxx = j * 2 + 1;
                x = p[i - j];
                y = p[i + j];
            }
        }
        for (int j = 0; i - j >= 0 && i + j + 1 < m; ++j)
        {
            if (s[i - j] != s[i + j + 1])
                break;
            if (j * 2 + 2 > maxx)
            {
                maxx = j * 2 + 2;
                x = p[i - j];
                y = p[i + j + 1];
            }
        }
    }
    cout << maxx << endl;
    for (int i = x; i <= y; ++i)
    {
        cout << buf[i];
    }
    cout << endl;
    return 0;
}