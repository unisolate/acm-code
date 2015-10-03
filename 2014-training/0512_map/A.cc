#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> PAIR;
struct cmp
{
    bool operator()(const PAIR &lhs, const PAIR &rhs)
    {
        return lhs.second > rhs.second;
    }
};
int main()
{
    int n;
    while (cin >> n && n)
    {
        string t;
        map<string, int> m;
        for (int i = 0; i < n; ++i)
            cin >> t, m[t]++;
        vector<PAIR> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp());
        cout << v[0].first << endl;
    }
    return 0;
}