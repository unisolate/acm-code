#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a[50];
        memset(a, 0, sizeof(a));
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
        	cout<<a[i]<<endl;
            if (a[i] > k)
                continue;
            int add = k / a[i];
            ans += add;
            k -= add * a[i];
            if (k == 0)
                break;
        }
        if (k == 0)
            cout << ans << endl;
        else cout << "-1" << endl;
    }
    return 0;
}