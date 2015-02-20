#include <stdio.h>
int main()
{
    long long r[51];
    r[1]=1;r[2]=2;
    int t=3;
    while(t<51)
    {
        r[t]=r[t-1]+r[t-2];
        t++;
    }
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("%I64d\n",r[n-m]);
    }
    return 0;
}