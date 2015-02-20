#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int t, x, y;
    cin >> t;
    while (t--)
    {
        int ans = 1;
        cin >> x >> y;
        int xx = x / 2, yy = y / 2, temp = 0;
        bool flag[222];
        for (int i = 1; i <= xx; ++i)
        {
            temp = 0;
            int a, b, c;
            if (y < i)
            {
                a = y; b = i; c = x - i;
            }
            else if (y > x - i)
            {
                a = i; b = x - i; c = y;
            }
            else
            {
                a = i; b = y; c = x - i;
            }
            memset(flag, false, sizeof(flag));
            flag[a] = true;
            flag[b] = true;
            flag[c] = true;
            flag[a + b] = true;
            flag[a + c] = true;
            flag[b + c] = true;
            flag[a + b + c] = true;
            flag[b - a] = true;
            flag[c - b] = true;
            flag[c - a] = true;
            flag[(b + c - a) > 0 ? (b + c - a) : (a - b - c)] = true;
            flag[(a + b - c) > 0 ? (a + b - c) : (c - a - b)] = true;
            flag[(a + c - b) > 0 ? (a + c - b) : (b - a - c)] = true;
            for (int j = 1; j < 221; ++j)
                if (flag[j])
                {
                    temp++;
                }
            if (temp > ans)
                ans = temp;
        }
        for (int i = 1; i <= yy; ++i)
        {
            temp = 0;
            int a, b, c;
            if (x < i)
            {
                a = x; b = i; c = y - i;
            }
            else if (x > y - i)
            {
                a = i; b = y - i; c = x;
            }
            else
            {
                a = i; b = x; c = y - i;
            }
            memset(flag, false, sizeof(flag));
            flag[a] = true;
            flag[b] = true;
            flag[c] = true;
            flag[a + b] = true;
            flag[a + c] = true;
            flag[b + c] = true;
            flag[a + b + c] = true;
            flag[b - a] = true;
            flag[c - b] = true;
            flag[c - a] = true;
            flag[(b + c - a) > 0 ? (b + c - a) : (a - b - c)] = true;
            flag[(a + b - c) > 0 ? (a + b - c) : (c - a - b)] = true;
            flag[(a + c - b) > 0 ? (a + c - b) : (b - a - c)] = true;
            for (int j = 1; j < 221; ++j)
                if (flag[j])
                    temp++;
            if (temp > ans)
                ans = temp;
        }
        cout << ans << endl;
    }
    return 0;
}