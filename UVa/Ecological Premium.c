#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,n,f,farmsize[20],animal[20],env[20],ans[20];
    memset (ans,0,sizeof(ans));
    scanf ("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf ("%d",&f);
        for (j=0;j<f;j++)
        {
            scanf ("%d %d %d",&farmsize[j],&animal[j],&env[j]);
            ans[i] += farmsize[j]*env[j];
        }
    }
    for (i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
