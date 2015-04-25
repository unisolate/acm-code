#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    int n, k, x, y;
    while (scanf("%d%d", &n, &k) && n + k)
    {
        stack<int> s;
        bool f = true;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            while (!s.empty() && x >= s.top())
                s.pop();
            if (!s.empty() && y > s.top()) f = false;
            s.push(y);
            if (s.size() > k) f = false;
        }
        if (f) puts("Sim"); else puts("Nao");
    }
    return 0;
}