/*
07.05.14 16:33	31 ms	158 kb
*/
#include <iostream>
#include <cstring>
#define MAXN 10001
using namespace std;
bool prime[MAXN];
int p[1230], sp[1000], d[MAXN], w[MAXN];
int findprime()
{
    prime[0] = true;
    prime[1] = true;
    int k = 1;
    for (int i = 2; i < MAXN; ++i)
        if (!prime[i])
        {
            p[k++] = i;
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = true;
        }
    k = 0;
    for (int i = 1; i < 1230; ++i)
        if (!prime[i])
            sp[k++] = p[i];
    return k;
}
int main()
{
    int k = findprime(), n;
    cin >> n;
    memset(d, 0x7f, sizeof(d));
    d[0] = 0;
    for (int i = 0; i < k; ++i)
        for (int j = sp[i]; j <= n; ++j)
            if (d[j - sp[i]] + 1 < d[j])
            {
                d[j] = d[j - sp[i]] + 1;
                w[j] = j - sp[i];
            }
    if (d[n] < 0x7f)
    {
        cout << d[n] << endl;
        int jj = n;
        for (int i = 1; i <= d[n] - 1; ++i)
        {
            cout << jj - w[jj] << " ";
            jj = w[jj];
        }
        cout << jj << endl;
    }
    else cout << 0 << endl;
    return 0;
}