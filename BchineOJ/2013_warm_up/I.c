#include <stdio.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,m,sum,big=0;
        scanf("%d",&n);
        int value[n];
        for(m=0;m<n;m++)
            scanf("%d",&value[m]);
        for(m=0;m<n-2;m++)
        {
            sum=value[m]+value[m+1]+value[m+2];
            if(big<sum)
                big=sum;
        }
        printf("%d\n",big);
    }
    return 0;
}
