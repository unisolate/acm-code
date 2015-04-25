#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char, int> p;
    p['^'] = 3;
    p['*'] = p['/'] = 2;
    p['+'] = p['-'] = 1;
    int t;
    char c;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        stack<char> s;
        while (scanf("%c", &c) && c != '\n')
        {
            if (isalnum(c)) putchar(c);
            else if (c == '(') s.push(c);
            else if (c == ')')
            {
                while (s.top() != '(') putchar(s.top()), s.pop();
                s.pop();
            }
            else
            {
                while (!s.empty()&& p[c] <= p[s.top()])
                    putchar(s.top()), s.pop();
                s.push(c);
            }
        }
        while (!s.empty())
            putchar(s.top()), s.pop();
        putchar(10);
    }
    return 0;
}
// 3+4*2/(1-5)^2^3
// 上面那组没修复也过了 数据太弱