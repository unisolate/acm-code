#include<stdio.h>
int m=0;
int main()
{
    int t,i,k;
    long a,b;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        m=0;
        scanf("%ld %ld",&a,&b);
        printf("%d\n",fuck(a,b));
    }
    return 0;
}

int fuck(int a,int b)
{
    int ans=0;
    if(b==1)
        ans=a+m;else
    if(a>b)
    {
        if(b==1)
            ans=a+m;else
        {
            m++;
            ans=fuck(a-b,b);
        }
    }else
    {
        if(a==1)
            ans=b+m;else
        {
            m++;
            ans=fuck(a,b-a);
        }
    }
    return ans;
}
