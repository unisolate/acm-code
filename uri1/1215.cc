#include <cstdio>
#include <map>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    char c;
    string s;
    map<string, int> m;
    while (~scanf("%c", &c))
    {
        if (isalpha(c))
        {
            s.push_back(tolower(c));
        }
        else
        {
            if (!s.empty())
            {
                m[s] = 1;
                s.clear();
            }
        }
    }
    for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i)
        printf("%s\n", i->first.c_str());
    return 0;
}