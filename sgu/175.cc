#include <bits/stdc++.h>
using namespace std;
int p(int l, int r, int pos)
{
    if (l == r) return pos;
    int m = l + r + 1 >> 1, k = m;
    if ((r - l + 1) % 2 == 0) --k;
    if (pos < m) return p(k + 1, r, l + r - pos);
    else return p(l, k, l + r - pos);
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    printf("%d\n", p(1, n, q));
    return 0;
}