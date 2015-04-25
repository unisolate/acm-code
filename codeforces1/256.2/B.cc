#include <cstdio>
#include <cstring>
using namespace std;
char x[233], y[233];
int main()
{
    scanf("%s%s", x, y);
    int lx = strlen(x), ly = strlen(y);
    if (lx < ly)
    {
        puts("need tree");
        return 0;
    }
    int m1[256], m2[256];
    memset(m1, 0, sizeof(m1));
    memset(m2, 0, sizeof(m2));
    for (int i = 0; i < lx; ++i)
        m1[x[i]]++;
    for (int i = 0; i < ly; ++i)
        m2[y[i]]++;
    if (lx == ly)
    {
        bool f = true;
        for (int i = 0; i < lx; ++i)
        {
            if ((m1[x[i]] != m2[x[i]]) || (m1[y[i]] != m2[y[i]]))
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            puts("array");
            return 0;
        }
    }
    int p = 0;
    for (int i = 0; i < lx; ++i)
    {
        if (x[i] == y[p])
        {
            ++p;
        }
        if (p >= ly)
            break;
    }
    if (p >= ly)
    {
        puts("automaton");
        return 0;
    }
    bool f = true;
    for (int i = 0; i < ly; ++i)
    {
        if (m2[y[i]] > m1[y[i]])
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        puts("both");
        return 0;
    }
    puts("need tree");
    return 0;
}