#include <stdio.h>
int main()
{
    int n;
    float i,ans=0.0;
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
    {
        ans =ans+(1/i);
    }
    printf ("%.3f",ans);
    return 0;
}
