#include <cstdio>
#include <cstring>
#include <stack>
#define MX 111111
using namespace std;
char s[MX], ans[MX];
int main()
{
    while (~scanf("%s", s))
    {
        stack<char> x, y;
        int len = strlen(s), p = 0;
        for (int i = 0; i < len; ++i)
        {
            // printf("#%d %d %d\n", i, x.size(), y.size());
            if (s[i] == '(' || s[i] == '[')
                x.push(s[i]), y.push(s[i]);
            else
            {
                if (!x.empty() && (x.top() == '(' && s[i] == ')') || (x.top() == '[' && s[i] == ']'))
                {
                    y.push(s[i]);
                    x.pop();
                }
                else
                {
                    if (x.empty() && y.size() > p)
                    {
                        p = y.size();
                        int k = p;
                        while (!y.empty())
                        {
                            ans[--k] = y.top();
                            y.pop();
                        }
                    }
                    else
                    {
                        while (!x.empty()) x.pop();
                        while (!y.empty()) y.pop();
                    }
                }
            }
        }
        while (!x.empty())
        {
            x.pop();
            if (!y.empty()) y.pop();
        }
        if (y.size() > p)
        {
            p = y.size();
            int k = p;
            while (!y.empty())
            {
                ans[--k] = y.top();
                y.pop();
            }
        }
        for (int i = 0; i < p; ++i)
            printf("%c", ans[i]);
        printf("\n\n");
    }
    return 0;
}