#include <bits/stdc++.h>
using namespace std;
int p[1111];
int main()
{
    int n, k;
    bool f = false;
    while (scanf("%d", &n) && n)
    {
        while (scanf("%d", &p[0]) && p[0])
        {
            for (int i = 1; i < n; ++i)
                scanf("%d", &p[i]);
            k = n;
            stack<int> s;
            for (int i = n - 1; i >= 0; --i)
            {
                s.push(p[i]);
                while (!s.empty() && s.top() == k)
                    s.pop(), --k;
            }
            puts(k ? "No" : "Yes");
        }
        putchar(10);
    }
    return 0;
}