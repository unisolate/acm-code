#include <cstdio>
using namespace std;
const int MX = 1e6;

int a[MX], b[MX], c[MX];

void update(int n)
{
    for (; n <= MX; n += (n & -n))
        ++c[n];
}

int query(int n)
{
    int sum = 0;
    for (; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i)
    {
        sum += query(b[i] - 1);
        update(a[i]);
    }
    printf("%d\n", sum);
    return 0;
}