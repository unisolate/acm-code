#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            q.push(i);
        printf("Discarded cards: 1");
        for (int i = 2; i < n; ++i)
        {
            q.pop(), q.push(q.front()), q.pop();
            printf(", %d", q.front());
        }
        q.pop();
        printf("\nRemaining card: %d\n", q.front());
    }
    return 0;
}