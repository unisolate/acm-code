#include <stdio.h>
int main()
{
    int i,n,m,x,height,amp,cas;
    scanf ("%d",&cas);
    for (i=1;i<=cas;i++)
    {
        scanf("%d %d",&height,&amp);
        for (n=1;n<=amp;n++)
        {
            for (m=1;m<=height;m++)
            {
                for (x=1;x<=m;x++)
                    printf ("%d",m);
                printf ("\n");
            }
            for (m=height-1;m>0;m--)
            {
                for (x=1;x<=m;x++)
                    printf ("%d",m);
                if (cas==i && n==amp && m==1)
                    continue;else
                    printf ("\n");
            }
            if (n!=amp)
                printf ("\n");
        }
    }
    return 0;
}
