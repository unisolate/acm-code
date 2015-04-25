/*
01.05.14 18:47	0 ms	50 kb
有2k个点排成一个圆，连接k条线使圆分割成最少的块，求最少块数和方案数。
这水题是越刷越少了……最少块数很容易知道是k+1.
方案数，考虑划分成子情况。
先看点1，可以和点2、4、6...2k连，有k种方案。
连完之后点被划分成两部分，方案数就是左边的乘上右边的。
例如k=3时有：
f(3)={
	f(0)*f(2)+
	f(1)*f(1)+
	f(2)*f(0)
}
最后结果挺大，k=30时方案有3814986502092304种= =
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int k;
    long long f[33];
    memset(f, 0, sizeof(f));
    cin >> k;
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= k; ++i)
    {
        for (int j = 0; j < i / 2; ++j)
            f[i] += 2 * (f[j] * f[i - j - 1]);
        if (i % 2)
            f[i] += f[i / 2] * f[i / 2];
    }
    cout << f[k] << " " << k + 1 << endl;
    return 0;
}