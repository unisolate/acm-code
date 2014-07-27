/*
15.05.14 18:35	31 ms	58 kb
*/
#include <iostream>
using namespace std;
int p[20][20];
bool f(int n, int q)
{
    int i = 1;
    bool f1 = true, f2 = false;
    if (q < 0)
    {
        q = -q;
        f1 = false;
    }
    while (p[n][i])
    {
        if (p[n][i] == q)
        {
            f2 = true;
            break;
        }
        ++i;
    }
    if (f1)
        return !f2;
    else return f2;
}
void z(int n)
{
    cout << p[n][0];
    int i = 1;
    while (p[n][i])
        cout << " " << p[n][i++];
    cout << endl;
}
int main()
{
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i][0];
        for (int j = 1; j <= p[i][0]; ++j)
            cin >> p[i][j];
    }
    while (m--)
    {
        cin >> k;
        int q[k], ans[10], c = 0;
        for (int i = 0; i < k; ++i)
        {
            cin >> q[i];
        }
        for (int i = 0; i < n; ++i)
        {
            bool flag = true;
            for (int j = 0; j < k; ++j)
            {
                if (f(i, q[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans[c++] = i;
            }
        }
        cout << c << endl;
        for (int i = 0; i < c; ++i)
        {
            z(ans[i]);
        }
    }
    return 0;
}