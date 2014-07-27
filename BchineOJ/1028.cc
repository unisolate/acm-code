#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        double r = (r1 + r2) * (r1 + r2);
        if (d > r)
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}