#include<stdio.h>
#include<string.h>
char b[10001], a[1000101];
int next[10001], m, n;
void NEXT()
{
    int i, j;
    next[0] = -1;
    i = 0;
    j = -1;
    while (i < m)
    {
        if (j == -1 || a[j] == a[i])
        {
            j++;
            i++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int KMP()
{
    int j = 0, i = 0, sum = 0;
    NEXT();
    while (i < n)
    {
        if (j == -1 || b[j] == a[i])
        {
            i++;
            j++;
        }
        else
            j = next[j];
        if (j == m) ////模串到头说明匹配成功
            sum++;
    }
    return sum;
}
int main()
{
    int sum, T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", b, a);
        m = strlen(b);
        n = strlen(a);
        sum = 0;
        sum = KMP();
        printf("%d\n", sum);
    }
    return 0;
}