#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 410000;
bool ok[maxn];
int f[maxn];
char s[maxn], ss[maxn];
int cnt[maxn];
void getFail(char *P, int *f)
{
    int m = strlen(P);
    f[0] = 0;
    f[1] = 0;
    for (int i = 1; i < m; i++)
    {
        int j = f[i];
        while (j && P[i] != P[j]) j = f[j];
        f[i + 1] = P[i] == P[j] ? j + 1 : 0;
    }
}
bool find(char *T, char *P, int *f)
{
    int n = strlen(T);
    int m = strlen(P);
    //    getFail(P,f);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j && P[j] != T[i]) j = f[j];
        if (P[j] == T[i]) j++;
        if (j == m) return true;
    }
    return false;
}
int tt;
int n, m, k;

int main()
{
    //    freopen("in.txt","r",stdin);
    while (~scanf("%s", ss))
    {
        int len = strlen(ss);
        for (int i = len - 1; i >= 0; i--)
            s[len - i - 1] = ss[i];
        s[len] = '\0';
        strcat(s, ss);
        getFail(s, f);
        int ans = min(len, f[strlen(s)]);
        printf("%s", ss);
        int ct = len - ans - 1;
        for (ct; ct >= 0; ct--)
            printf("%c", ss[ct]);
        puts("");
    }
    return 0;
}
