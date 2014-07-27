/*
28.04.14 16:07	15 ms	70 kb
序列1, 12, 123, 1234, ..., 12345678910, ...
求前N项中能被3整除的数的个数
*/
#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    cout << n / 3 * 2 + (long long)(((n % 3) == 2) ? 1 : 0) << endl;
    return 0;
}