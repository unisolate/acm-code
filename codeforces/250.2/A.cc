#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
using namespace std;
struct cho
{
    int pos, len;
} l[4];
int cmp(struct cho a, struct cho b)
{
    return a.len < b.len;
}
int main()
{
    char p[4][111];
    for (int i = 0; i < 4; ++i)
    {
        scanf("%s", p[i]);
        l[i].len = strlen(p[i]) - 2;
        l[i].pos = i;
    }
    sort(l, l + 4, cmp);
    if (l[0].len * 2 <= l[1].len && l[3].len < l[2].len * 2)
        printf("%c\n", l[0].pos + 'A');
    else if (l[3].len >= l[2].len * 2 && l[0].len * 2 > l[1].len)
        printf("%c\n", l[3].pos + 'A');
    else printf("C\n");
    return 0;
}