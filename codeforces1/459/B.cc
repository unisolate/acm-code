#include <bits/stdc++.h>
#define INF (int)1e9+9
using namespace std;
int p[222222];
int main()
{
    int n, _min = INF, _max = -1;
    long long a = 0, b = 0, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i]);
        if (p[i] < _min)_min = p[i];
        if (p[i] > _max)_max = p[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (p[i] == _min)++a;
        if (p[i] == _max)++b;
    }
    if (_min != _max)
        ans = a * b;
    else ans = a * (a - 1) / 2;
    printf("%d %I64d", _max - _min, ans);
    return 0;
}