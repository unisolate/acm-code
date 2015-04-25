#include <bits/stdc++.h>
using namespace std;
struct w
{
    char s[111];
    int i, l;
} p[111];
char s[22222];
int cmp(w a, w b)
{
    if (a.l == b.l) return a.i < b.i;
    return a.l > b.l;
}
int main()
{
    int t;
    scanf("%d", &t), getchar();
    while (t--)
    {
        gets(s);
        int l = strlen(s), k = 0, x = 0;
        for (int i = 0; i <= l; ++i)
            if (s[i] != ' ' && s[i] != '\0') p[k].s[x++] = s[i];
            else p[k].i = k, p[k].s[x++] = '\0', p[k++].l = x, x = 0;
        sort(p, p + k, cmp);
        for (int i = 0; i < k - 1; ++i)
            printf("%s ", p[i].s);
        printf("%s\n", p[k - 1].s);
    }
    return 0;
}