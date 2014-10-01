#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    int n, t, p;
    while (~scanf("%d", &n))
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool f[3];
        for (int i = 0; i < 3; ++i) f[i] = true;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &t, &p);
            if (t == 1)
            {
                s.push(p);
                q.push(p);
                pq.push(p);
            }
            else
            {
                if (s.top() != p)
                    f[0] = false;
                s.pop();
                if (q.front() != p)
                    f[1] = false;
                q.pop();
                if (pq.top() != p)
                    f[2] = false;
                pq.pop();
            }
        }
        int k = 0;
        for (int i = 0; i < 3; ++i)
            if (f[i])
                ++k;
        if (k == 0)
            puts("impossible");
        else if (k == 1)
        {
            if (f[0])
                puts("stack");
            else if (f[1])
                puts("queue");
            else puts("priority queue");
        }
        else puts("not sure");
    }
    return 0;
}