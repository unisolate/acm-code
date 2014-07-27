#include <cstdio>
#include <cstring>
#define MX 1024
using namespace std;
typedef unsigned long long ull;
const ull B = 100000007ULL;
char s[MX];
inline ull get(int pos, int l)
{
    ull ha = 0ULL;
    if (l > 0)
    {
        for (int i = 0; i < l; ++i)
            ha = ha * B + s[pos + i];
    }
    else
    {
        l = -l;
        for (int i = l - 1; i >= 0; --i)
            ha = ha * B + s[pos + i];
    }
    return ha;
}
bool check(int p, int q)
{
    if (p == q)
        return true;
    bool f[2];
    for (int i = 0; i < 2; ++i)
    {
        f[i] = true;
        for (int j = 0; j < 3; ++j)
        {
            if (s[p + j] != s[q + i + j])
                f[i] = false;
        }
    }
    if (f[0] || f[1])
        return true;
    return false;
}
int main()
{
    while (~scanf("%s", s))
    {
        int len = strlen(s), pi[MX], x = 0, y = 0;
        ull pre[MX];
        bool flag = true;
        for (int i = 0; i < len - 2; ++i)
        {
            if (get(i, 3) == get(i, -3))
            {
                if (flag)
                    flag = false;
                else
                {
                    bool f = true;
                    for (int j = 0; j < y; ++j)
                        if (get(i, 3) == pre[j])
                            f = false;
                    if (f)
                    {
                        printf("%s\n", s);
                        break;
                    }
                }
                pre[y++] = get(i, 3);
                pi[x++] = i;
            }
            if (get(i, 4) == get(i, -4))
            {
                if (flag)
                    flag = false;
                else
                {
                    bool f = true;
                    for (int j = 0; j < y; ++j)
                        if (get(i, 4) == pre[j])
                            f = false;
                    for (int j = 0; j < x; ++j)
                        if (check(pi[j], i))
                            f = false;
                    if (f)
                    {
                        printf("%s\n", s);
                        break;
                    }
                }
                pre[y++] = get(i, 4);
            }
        }
    }
    return 0;
}