#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int MX = 100010;
const ull B = 100000007ULL;
char s[2][MX], q[MX];
ull ha[2][MX], bp[MX] = {1ULL};
int len[2];
void init()
{
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j < len[i] + 1; ++j)
            ha[i][j] = ha[i][j - 1] * B + s[i][j];
    int n = max(2, max(len[0], len[1]));
    for (int i = 1; i < n + 1; ++i)
        bp[i] = bp[i - 1] * B;
}
inline ull hash(ull *Ha, int pos, int l)
{
    return Ha[pos + l - 1] - Ha[pos - 1] * bp[l];
}
int overlap(int a, int b)
{
    int ans = 0;
    for (int i = 1; i < min(len[a], len[b]) + 1; ++i)
        if (hash(ha[a], len[a] - i + 1, i) == hash(ha[b], 1, i))
            ans = i;
    return ans;
}
int main()
{
    while (~scanf("%s", q))
    {
        strcpy(s[0] + 1, q);
        len[0] = len[1] = strlen(s[0] + 1);
        for (int i = 1; i <= len[0]; ++i)
            s[1][i] = s[0][len[0] - i + 1];
        s[1][len[0] + 1] = '\0';
        init();
        int p = overlap(0, 1);
        for (int i = 1; i < len[0] - p + 1; ++i)
            printf("%c", s[0][i]);
        //printf("-");
        for (int i = 1; i <= len[0]; ++i)
            printf("%c", s[1][i]);
        putchar(10);
    }
    return 0;
}