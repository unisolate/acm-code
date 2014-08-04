#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("name.in", "r", stdin);
    freopen("2.out", "w", stdout);
    char c;
    while (~scanf("%c", &c))
        if (isalpha(c))
            printf("%c", c);
    return 0;
}