#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Cow
{
    long long v, x;
} cows[20001];
long long a[20001], b[20001];
int n;
int cmp(struct Cow a, struct Cow b)
{
    return a.v < b.v;
}
void update(int i, long long val, long long *array)
{
    for (; i <= 20000; i += (i & -i))
        array[i] += val;
}
long long read(int i, long long *array)
{
    long long sum = 0;
    for (; i > 0; i -= (i & -i))
        sum += array[i];
    return sum;
}
int main()
{
    int m;
    long long sum = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    for (m = 0; m < n; m++)
        scanf("%lld %lld", &cows[m].v, &cows[m].x);
    sort(cows, cows + n, cmp);
    for (m = 0; m < n; m++)
    {
        update(cows[m].x, cows[m].x, a);
        update(cows[m].x, 1, b);
        sum += (cows[m].x * read(cows[m].x - 1, b) - read(cows[m].x - 1, a) + read(20000, a)
                - read(cows[m].x, a) - cows[m].x * (m + 1 - read(cows[m].x, b))) * cows[m].v;
    }
    printf("%lld\n", sum);
    return 0;
}