#include <bits/stdc++.h>
using namespace std;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        while (n--)
            scanf("%d", &p), h[p % m][q[p % m]++] = p;
    }
    return 0;
}