#include <stdio.h>
int main()
{
    int n,m,i,a=0;
    scanf ("%d",&n);

    int num[n];
    for (i=0;i<n;i++)
        scanf ("%d",&num[i]);

    scanf ("%d",&m);

    for (i=0;i<n;i++)
    {
        if(num[i]<m)
        a++;
    }

    printf ("%d",a);
    return 0;
}
