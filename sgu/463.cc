/*
16.05.14 17:59	15 ms	114 kb
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, sum = 0, p[111][111];
bool f[111][111];
void add(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return;
    if (!f[x][y])
    {
        sum += p[x][y];
        f[x][y] = true;
    }
    else sum += p[x][y] / 2;
}
int main()
{
    memset(f, false, sizeof(f));
    cin >> n >> m;
    char q[m + 10];
    for (int i = 1; i <= n; ++i)
    {
        cin >> q;
        for (int j = 1; j <= m; ++j)
            p[i][j] = q[j - 1] - '0';
    }
    char s[555];
    int x = 0, y = 0, d = 0, r = 1, a = 1, b = 2, c[4] = { -1, 0, 1, 0};
    cin >> s;
    for (int i = 0; i < strlen(s); ++i)
    {
        switch (s[i])
        {
        case 'R':
            a += 1;
            if (a > 3)a = 0;
            d = c[a];
            b += 1;
            if (b > 3)b = 0;
            r = c[b];
            break;
        case 'L':
            a -= 1;
            if (a < 0)a = 3;
            d = c[a];
            b -= 1;
            if (b < 0)b = 3;
            r = c[b];
            break;
        case 'M':
            x += d;
            y += r;
            // cout << x << " " << y << endl;
            if (d == 0)
            {
                if (r > 0)
                {
                    add(x, y);
                    add(x + 1, y);
                }
                else
                {
                    add(x, y + 1);
                    add(x + 1, y + 1);
                }
            }
            else if (r == 0)
            {
                if (d > 0)
                {
                    add(x, y);
                    add(x, y + 1);
                }
                else
                {
                    add(x + 1, y);
                    add(x + 1, y + 1);
                }
            }
            break;
        }
    }
    cout << sum << endl;
    return 0;
}