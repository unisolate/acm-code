/*
29.04.14 20:01	0 ms	50 kb
神坑!
判断N是否可以写成两素数的乘积,N最大10^9
开始写的打素数表,无奈改了好几种方式,都太占空间,MLE几次,表开小也没法过.
改用直接判断素数方式,WA&TLE几次后变换判断方法终于A掉...
*/
#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int num)
{
    if (num == 2 || num == 3 || num == 5) return true;
    unsigned long c = 7;
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num == 1) return false;
    int maxc = int(sqrt(num));
    while (c <= maxc)
    {
        if (num % c == 0) return false;
        c += 4;
        if (num % c == 0) return false;
        c += 2;
        if (num % c == 0) return false;
        c += 4;
        if (num % c == 0) return false;
        c += 2;
        if (num % c == 0) return false;
        c += 4;
        if (num % c == 0) return false;
        c += 6;
        if (num % c == 0) return false;
        c += 2;
        if (num % c == 0) return false;
        c += 6;
    }
    return true;
}
int main()
{
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        bool flag = true;
        int up = sqrt(x) + 1;
        for (int i = 2; i < up; ++i)
        {
            if ((x % i) == 0 && isprime(i) && isprime(x / i))
            {
                cout << "Yes" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "No" << endl;
    }
}