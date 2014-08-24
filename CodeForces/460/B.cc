#include <bits/stdc++.h>
using namespace std;
int ans[111];
int main()
{
    int a, b, c, k = 0;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i <= 111; ++i)
    {
        long long z = i;
        for (int j = 1; j < a; ++j)
            z *= i;
        long long t = b * z + c;
        long long s = 0;
        if (t >= 1000000000 || t <= 0)
            continue;
        int p = t;
        while (t)
        {
            s += t % 10;
            t /= 10;
        }
        //printf("#%d %d\n",p,s);
        if (s == i)
            ans[k++] = p;
    }
    sort(ans, ans + k);
    printf("%d\n", k);
    for (int i = 0; i < k - 1; ++i)
        printf("%d ", ans[i]);
    if (k)
        printf("%d\n", ans[k - 1]);
    return 0;
}