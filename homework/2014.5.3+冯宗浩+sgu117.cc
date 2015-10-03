/*
03.05.14 20:03  46 ms   150 kb
本题关键在于判断N的M次方能否整除K。
M最大到10000，所以不能直接运算。
可以将N和M分别分解质因数，然后一一对比每个质因数的个数，N的质因数个数乘以M再比较。
一整天舟车劳顿，代码也混乱不堪啊= =
*/
#include <iostream>
#include <cstring>
#define MAXN 10001
using namespace std;
bool prime[MAXN];
int flag[2000], pp[MAXN], kk[MAXN];
void findprime()
{
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < MAXN; i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < MAXN; i++)
        if (prime[i])
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = false;
    int a = 0;
    for (int i = 2; i < MAXN; ++i)
        if (prime[i])
        {
            flag[a++] = i;
            //cout << flag[a - 1] << " ";
        }
}
int main()
{
    findprime();
    memset(kk, 0, sizeof(kk));
    int n, m, k, ans = 0, a = 0, p;
    cin >> n >> m >> k;
    while (k > flag[a])
    {
        if (k % flag[a])
            a++;
        else
        {
            kk[flag[a]]++;
            k /= flag[a];
        }
    }
    kk[k]++;
    for (int i = 0; i < n; ++i)
    {
        memset(pp, 0, sizeof(pp));
        cin >> p;
        a = 0;
        while (p > flag[a])
        {
            if (p % flag[a])
                a++;
            else
            {
                pp[flag[a]]++;
                p /= flag[a];
            }
        }
        pp[p]++;
        bool fl = true;
        for (int j = 0; j < 2000; ++j)
        {
            //cout << kk[flag[j]] << " " << pp[flag[j]] << endl;
            if (kk[flag[j]] > pp[flag[j]]*m)
            {
                fl = false;
                break;
            }
        }
        if (fl)
            ans++;
    }
    cout << ans << endl;
    return 0;
}