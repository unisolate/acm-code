#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    string s;
    scanf("%d", &t);
    while (t--)
    {
        double p, ans = 0;
        map<string, double> m;
        scanf("%d", &n);
        while (n--)
            cin >> s >> p, m[s] = p;
        scanf("%d", &n);
        while (n--)
            cin >> s >> p, ans += m[s] * p;
        printf("R$ %.2lf\n", ans);
    }
    return 0;
}