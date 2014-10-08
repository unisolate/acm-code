#include <cstdio>
#include <cstring>
#define MX (int)1e6+10
using namespace std;
int n, m, p[MX];
char a[MX];
void init()
{
    p[0] = -1;
    int i = 0, j = -1;
    while (i < m)
        if (j == -1 || b[i] == b[j])
            ++i, ++j, p[i] = j;
        else j = p[j];
}
int kmp()
{
    int i = 0, j = 0, ans = 0;
    while (i < n)
    {
        if (j == -1 || b[j] == a[i])
            ++i, ++j;
        else j = p[j];
        if (j == m)
            ++ans;
    }
    return ans;
}
int main()
{
    int cas = 0;
    while (scanf("%d", &n) && n)
    {
        scanf("%s", a);
        m = strlen(b);
        printf("Test case #%d\n", ++cas);
        init();
        putchar(10);
    }
    return 0;
}