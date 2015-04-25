/*
04.05.14 10:48	31 ms	58 kb
定义「数字根」是一个数的每一位相加，大于9时反复操作，最后得到的只有一位的数。
给出数列AN，求这个表达式
A1*A2*…*AN + A1*A2*…*AN-1 + … + A1*A2 + A1.
的「数字根」。
由于每个数最大到10^9，所以不能直接运算了。
发现一每个数的数字根代替进行运算，结果是一样的。
再把表达式写成A1*(1+A2*(1+A3*(...(1+AN))))，方便运算。
*/
#include <iostream>
using namespace std;
int s(int p)
{
    if (p < 10)
        return p;
    if (p == 10)
        return 1;
    int n = 10, a = 0, k;
    while (p / 10 > n)
        n *= 10;
    while (n > 1)
    {
        k = p / n;
        a += k;
        p -= k * n;
        n /= 10;
    }
    a += p;
    return s(a);
}
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        int p[n], f[n], ans = 1;
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
            f[i] = s(p[i]);
        }
        for (int i = n - 1; i > 0; --i)
        {
            ans = s(ans * f[i] + 1);
        }
        ans *= f[0];
        cout << s(ans) << endl;
    }
    return 0;
}