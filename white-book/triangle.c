#include <stdio.h>
int main()
{
    int n,i,i1,i2,i3;
    scanf ("%d",&n);
    for (i=0,i2=n;i<n;i++,i2--)
    {
        for (i1=0;i1<i;i1++)
            printf(" ");
        for (i3=0;i3<i2*2-1;i3++)
            printf("#");
        printf ("\n");
    }
    return 0;
}
