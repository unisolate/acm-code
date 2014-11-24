#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,q,i,m,x,solve;
    long y=0,a[1000];
    memset(a,0,sizeof(a));
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&q);
        for(m=0;m<n;m++)
            scanf("%ld",&a[m]);
        for(m=0;m<q;m++)
        {
            scanf("%ld",&y);
            for(x=1,solve=0;x<n;x++)
            {
                if(a[x-1]>a[x])
                {
                    if(y<=a[x-1] && y>a[x])
                        solve++;
                }
                if(a[x-1]<a[x])
                {
                    if(y>=a[x-1] && y<a[x])
                        solve++;
                }
                if(a[x-1]==a[x] && y==a[x])
                {
                    solve=-2;
                    break;
                }
            }
            if(y==a[n-1])
                solve++;
            if(solve<0)
                printf("Infinite\n");else
                printf("%d\n",solve);
        }
    }
    return 0;
}
