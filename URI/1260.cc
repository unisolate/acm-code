#include <bits/stdc++.h>
using namespace std;
char s[50];
int main()
{
    int t;
    bool f = false;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        if (f) putchar(10); else gets(s), f = true;
        map<string, int> m;
        int k = 0;
        while (gets(s) && s[0] != '\0')
            ++m[s], ++k;
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it)
            cout << it->first, printf(" %.4lf\n", it->second / (double)k * 100);
    }
    return 0;
}