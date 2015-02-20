#include <iostream>
using namespace std;
int p[33], num;
void init()
{
    for (int i = 0; i < 33; ++i)
        p[i] = i;
}
int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}
void uni(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    num--;
    p[x] = y;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m;
        num = n;
        init();
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            uni(a > b ? b : a, a > b ? a : b);
        }
        cout << num << endl;
    }
    return 0;
}