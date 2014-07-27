#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long m, p[3], q[3], n[3], k[3];
int main()
{
    char s[111];
    scanf("%s", s);
    for (int i = 0; i < 3; ++i)
        scanf("%I64d", &p[i]);
    for (int i = 0; i < 3; ++i)
        scanf("%I64d", &q[i]);
    scanf("%I64d", &m);
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == 'B')
            ++n[0];
        else if (s[i] == 'S')
            ++n[1];
        else ++n[2];
    }
    long long y = 0, l = 1e13, r = -1;
    for (int i = 0; i < 3; ++i)
        if (n[i] > 0)
        {
            k[i] = p[i] / n[i];
            l = min(l, k[i]);
            r = max(r, k[i]);
            y += n[i] * q[i];
        }
    long long t = m, z = l;
    bool flag = true;
    for (long long i = l; i <= r; ++i)
    {
        t = m;
        for (int j = 0; j < 3; ++j)
        {
            if (n[j] > 0)
            {
                if (k[j] < i)
                    t -= q[j] * (n[j] * i - p[j]);
                if (t < 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag)
            break;
        z = i;
    }
    if (flag && t > 0)
        z += t / y;
    printf("%I64d\n", z);
    return 0;
}