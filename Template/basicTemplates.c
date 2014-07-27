#include <algorithm>
//sort(a, a + 10, cmp);
int cmp(int a, int b)
{
    return a < b;
}
//sort struct
struct node
{
    int n, m;
} c[MAXN];

//sort only by n , increase
int cmp(struct node a, struct node b)
{
    return a.n < b.n;
}

//sort firstly by n, secondly by m, increase
bool cmp(struct node a, struct node b)
{
    if(a.n == b.n)
        return a.m < b.m;
    else
        return a.n < b.n;
}
//usage: sort(c,c+MAXN,cmp);

