/*
28.04.14 16:16	15 ms	66 kb
求N条直线最多能把平面划分成几块
*/
#include <iostream>
using namespace std;
int main()
{
    long long n, ans;
    cin >> n;
    ans = n * (n + 1) / 2 + 1;
    cout << ans << endl;
    return 0;
}