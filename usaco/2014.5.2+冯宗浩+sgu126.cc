/*
有两个盒子，分别装a、b个球。每次操作，只能将一个盒子中等于另外一个盒子中球的数目的球，移动到另一个盒子中。
问多少次操作后能全部移到一个盒子里。永远不能输出-1。
被坑的略惨。先是未考虑有ab中一个为0的情况卡在test 3，改正后然后又卡在test 14.
自己发现的规律是大数为小数的(2^n-1)倍时则能够成功。
网上题解思路一致指向若a+b为奇数则失败，然后a和b不断约公因数再继续判断。
公式2^k=(a+b)/gcd(a,b),k即为答案。
先睡了，明天必须研究出自己那里错了……
*/
/*WA Code*/
#include <iostream>
#include <cmath>
using namespace std;
void run(long long a, long long b)
{
    if (b == 0)
    {
        cout << "0" << endl;
        return;
    }
    long long n = 1, t = 2;
    while (a >= (t - 1)*b)
    {
        if (a == (t - 1)*b)
        {
            cout << n << endl;
            return;
        }
        t *= 2;
        n++;
    }
    cout << "-1" << endl;
}
// void run(long long a, long long b)
// {
//     if (!b)
//     {
//         cout << "0" << endl;
//         return;
//     }
//     if (a % b == 0)
//     {
//         int t = a / b;
//         if (!((t + 1) & (t)))
//         {
//             cout << log(t + 1) / log(2) << endl;
//             return;
//         }
//     }
//     cout << "-1" << endl;
// }
int main()
{
    long long a, b;
    cin >> a >> b;
    if (a >= b)
        run(a, b);
    else run(b, a);
    return 0;
}

/*AC Code*/
#include <cstdio>
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0 || b == 0)
    {
        printf("0\n");
        return 0;
    }
    long long s = (a + b) / gcd(a, b);
    for (long long i = 1; i < 32; i++)
        if ((long long)1 << i == s)
        {
            printf("%lld\n", i);
            return 0;
        }
    printf("-1\n");
    return 0;
}