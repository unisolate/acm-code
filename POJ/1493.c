#include <stdio.h>
int main()
{
    int n,i,j;
    scanf ("%d",&n);
    while (n>0)
    {
        int x[n],maxx=0,ans=0;
        for(i=1;i<=n;i++)
        {
            x[i]=0;
            for(j=1;j<=26;j++)
            {
                if(getchar()=='X')
                    x[i]++;
            }
            if(maxx<x[i])
                maxx=x[i];
        }
        for(i=1;i<=n;i++)
        {
            ans+=maxx-x[i];
        }
        printf("%d\n",ans);
        scanf ("%d",&n);
    }
    return 0;
}
