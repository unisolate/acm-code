#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct n
{
    int a, b;
} num[55555];
int cmp(n x, n y)
{
    if (x.a == y.a)
        return x.b > y.b;
    else return x.a > y.a;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(num, 0, sizeof(num));
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i].a >> num[i].b;
        }
        sort(num, num + n, cmp);
        cout << num[k - 1].a << " " << num[k - 1].b << endl;
    }
    return 0;
}