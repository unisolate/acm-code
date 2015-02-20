/*
696K	0MS
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
    int n;
    while (cin >> n && n)
    {
        int p[n];
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        sort(p, p + n, cmp);
        bool flag = false;
        if (!(n % 2))
        {
            for (int i = 0; i < n; i += 2)
                if (p[i] != p[i + 1])
                    flag = true;
        }
        else flag = true;
        if (flag)
            cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}