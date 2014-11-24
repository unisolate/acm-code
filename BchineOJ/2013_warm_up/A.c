#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,n,a;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        int num[n-1],m;
        memset(num,0,sizeof(num));
        for(m=0;m<n-1;m++)
            scanf("%d",&num[m]);
        a=num[0];
        for(m=0;m<n-1;m++)
        {
            if(a>=num[m])
                a=num[m];
        }
        if(a==0)
            a=1;
        printf("%d\n",a);
    }
    return 0;
}
