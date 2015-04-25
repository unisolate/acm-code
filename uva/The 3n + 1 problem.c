#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,a,cycle,ans=0;
    while (scanf ("%d %d",&m,&n) == 2)
    {
        for (a=min(m,n);a<=max(m,n);a++)
        {
            for (cycle=0;a!=1;cycle++)
            {
                if (a%2 == 0)
                    a=a/2;
                else
                    a=a*3+1;
            }
            if (ans<cycle)
                ans=cycle;
        }
        printf ("%d %d %d\n",m,n,ans);
    }
    return 0;
}
