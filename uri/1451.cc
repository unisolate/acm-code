#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <list>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        list<char> l;
        list<char>::iterator it = l.begin();
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '[')
                it = l.begin();
            else if (s[i] == ']')
                it = l.end();
            else l.insert(it, s[i]);
        }
        for (it = l.begin(); it != l.end(); ++it)
            printf("%c", *it);
        putchar(10);
    }
    return 0;
}