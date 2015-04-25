/*
29.04.14 20:49	15 ms	54 kb
水题,判断分钟数输出相应情况即可.好几次才A,粗心大意,罪过罪过.
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int s, p, d, ans = 0;
    while (cin >> s >> p)
    {
        d = (p - s) / 60;
        if (p - s > 0 && p - s < 60)
            d++;
        if (d == 0)
            ans = 0;
        else if (d > 0 && d < 5)
            ans = 1;
        else if (d >= 5 && d < 15)
            ans = 2;
        else if (d >= 15 && d < 30)
            ans = 3;
        else if (d >= 30)
            ans = 4;
        if (s > p)
            ans = 0;
        cout << ans << endl;
    }
    return 0;
}