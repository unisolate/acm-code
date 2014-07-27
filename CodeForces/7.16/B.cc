#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 222
typedef unsigned long long ull;
using namespace std;
const ull B = 100000007ULL;
char s[MAXL];
int len;
ull ha[MAXL], bp[MAXL] = {1ULL};
void hash()
{
    ha[0] = s[0];
    for (int i = 1; i < len; ++i)
        ha[i] = ha[i - 1] * B + s[i], bp[i] = bp[i - 1] * B;
}
ull get(int pos, int l)
{
    return ha[pos + l - 1] - ha[pos - 1] * bp[l];
}
bool check(int p, int l)
{
    return get(p, min(l, len - p - l)) == get(p + l, min(l, len - p - l));
}
int main()
{
    int k;
    scanf("%s%d", s, &k);
    len = strlen(s);
    if (k >= len)
    {
        printf("%d\n", 2 * ((k + len) >> 1));
        return 0;
    }
    hash();
    for (int i = (len + k) >> 1; i >= k; --i)
    {
        for (int j = 0; j <= len + k - 2 * i; ++j)
        {
            if (check(j, i))
            {
                printf("%d\n", 2 * i);
                return 0;
            }
        }
    }
}
// bool check(int p, int l)
// {
//     for (int i = 0; i < l; ++i)
//     {
//         if (p + l + i >= len)
//             return true;
//         if (s[p + i] != s[p + l + i])
//             return false;
//     }
//     return true;
// }