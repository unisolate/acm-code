#include <cstdio>
#include <cstring>
int main()
{
    int x;
    scanf("%d", &x);
    for (int cas = 0; cas < x; ++cas)
    {
        int n, m, k, p = 0;
        char op[3];
        scanf("%d%d", &n, &k);
        int t[n];
        memset(t, 0, sizeof(t));
        while (k--)
        {
            scanf("%s%d", op, &m);
            if (op[0] == 'D')
            {
                bool flag1 = false;
                for (int i = 0; i < n; ++i)
                {
                    bool flag2 = true;
                    int pos = (p + i) % n;
                    for (int j = 0; j <= m; ++j)
                    {
                        if (t[(pos + j) % n] == 2)
                            flag2 = false;
                    }
                    if (flag2)
                    {
                        flag1 = true;
                        p = pos;
                        break;
                    }
                }
                if (flag1)
                {
                    printf("The launderer gives ticket %d.\n", p);
                    t[p] = 1;
                    for (int i = 1; i <= m; ++i)
                    {
                        int pos = (p + i) % n;
                        t[pos] = 2;
                    }
                    p += m + 1;
                }
                else
                {
                    printf("No space left, please come back later.\n");
                }
            }
            else
            {
                printf("The launderer gives back batch %d.\n", m);
                if (t[(m - 1 + n) % n] == 0)
                    printf("%d is freed.\n", m);
                t[m] = 0;
                int pos = (m + 1) % n;
                while (t[pos] == 2)
                {
                    t[pos] = 0;
                    printf("%d is freed.\n", pos);
                    pos = (pos + 1) % n;
                }
            }
        }
        if (cas != x - 1)
            printf("\n");
    }
    return 0;
}