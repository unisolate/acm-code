#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int n[20];
    while (scanf("%d", &n[0]) && n[0] != -1)
    {
        int k = 1, ans = 0;
        while (scanf("%d", &n[k]) && n[k])
            ++k;
        sort(n, n + k, cmp);
        for (int i = 0; i < k - 1; ++i)
        {
            for (int j = i + 1; j < k; ++j)
                if (n[j] == 2 * n[i])
                    ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}