/*
28.04.14 20:32	15 ms	70 kb
*/
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int p, m, c, k, r, v;
    cin >> p >> m >> c >> k >> r >> v;
    int x[3] = {p / k, m / r, c / v};
    sort(x, x + 3, cmp);
    cout << x[0] << endl;
    return 0;
}