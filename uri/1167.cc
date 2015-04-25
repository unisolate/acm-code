#include <cstdio>
#include <cstring>
using namespace std;

char s[111][111];
int v[111];
bool f[111];

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        memset(f, false, sizeof(f));
        for (int i = 0; i < n; ++i)
            scanf("%s%d", s[i], &v[i]);
        int p = 0;
        bool d = true;
        for (int i = 0; i < n; ++i)
        {
            int t = v[p];
            if (t % 2)
                d = true;
            else d = false;
            for (int j = 0; j < t;)
            {
                if (d) ++p; else --p;
                if (p == n) p = 0;
                if (p < 0) p = n - 1;
                if (f[p] == false) ++j;
            }
            f[p] = true;

        }
        printf("Vencedor(a): %s\n", s[p]);
    }
    return 0;
}