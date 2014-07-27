#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;
map<string, int> m;
map<string, int>::iterator iter, end;
map<char, char> t;
int main()
{
    t['A'] = t['B'] = t['C'] = '2';
    t['D'] = t['E'] = t['F'] = '3';
    t['G'] = t['H'] = t['I'] = '4';
    t['J'] = t['K'] = t['L'] = '5';
    t['M'] = t['N'] = t['O'] = '6';
    t['P'] = t['R'] = t['S'] = '7';
    t['T'] = t['U'] = t['V'] = '8';
    t['W'] = t['X'] = t['Y'] = '9';
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char s[100];
        string p = "";
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; ++i)
        {
            if (isdigit(s[i]))
                p += s[i];
            else if (isalpha(s[i]))
            {
                if (s[i] == 'Q' || s[i] == 'Z')
                    continue;
                p += t[s[i]];
            }
        }
        p.insert(3, "-");
        m[p]++;
    }
    bool flag = true;
    iter = m.begin();
    end = m.end();
    while (iter != end)
    {
        if ((iter->second) > 1)
        {
            flag = false;
            cout << iter->first << " " << iter->second << endl;
            // printf("%s %d\n", iter->first, iter->second);
        }
        ++iter;
    }
    if (flag)
        printf("No duplicates.\n");
    return 0;
}