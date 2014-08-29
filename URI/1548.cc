#include <bits/stdc++.h>
using namespace std;
int p[1111], q[1111];
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]), q[i] = p[i];
        sort(q, q + n);
        int s = 0;
        for (int i = 0; i < n; ++i)
            if (p[i] == q[n - i - 1])
                ++s;
        printf("%d\n", s);
    }
    return 0;
}