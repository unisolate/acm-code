#include <bits/stdc++.h>
using namespace std;
int c[9][9] = {1, 2, 3, 4, 5};
int main()
{
    memset(c, 1, sizeof(c));
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            printf("%d ", c[i][j]);
    return 0;
}