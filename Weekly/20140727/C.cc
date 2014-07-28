#include <bits/stdc++.h>
using namespace std;
class SquareDivisor
{
public:
    long long biggest(long long n)
    {
        long long ans, m = sqrt(n);
        for (long long i = m; i >= 1; --i)
        {
            long long t = i * i;
            if (n % t == 0)
            {
                ans = t;
                break;
            }
        }
        return ans;
    }
};
