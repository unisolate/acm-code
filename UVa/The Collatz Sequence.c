#include <stdio.h>
int main()
{
    int n,a,i,limit,term;
    for (n=1;;n++)
    {
        scanf ("%d %d",&a,&limit);
        i=a;
        for (term=0;a<=limit;term++)
        {
            if (a%2==0)
                a=a/2;
            else
                a=a*3+1;
        }
        printf ("Case %d: A = %d, limit = %d, number of terms = %d\n",n,i,limit,term);
    }
    return 0;
}
