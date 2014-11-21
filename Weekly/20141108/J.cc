#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int p[111];
int main()
{
    int t, cas = 0, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        sort(p, p + n);
        map<pair<pair<int, int>, int>, int> m;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                {
                    if (p[i] + p[j] > p[k])
                        m[make_pair(make_pair(p[i], p[j]), p[k])]++;
                }
        // printf("Case #%d: %lu\n", ++cas, m.size());
        ++cas;
        cout << "Case #" << cas << ": " << m.size() << endl;
    }
    return 0;
}