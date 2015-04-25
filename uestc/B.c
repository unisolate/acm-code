#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        long a,b,t,t1;
        double ans=1;
        scanf("%ld %ld %ld %ld",&a,&b,&t,&t1);
        if(t1<a || t1>b+t)
            ans=0;
        else
        {
            if(a+t>=b)
            {
                if(t1>=b && t1<=a+t)
                    ans=1;else
                if(t1<b)
                    ans=(double)(t1-a)/(b-a);else
                    ans=(double)(b+t-t1)/(b-a);
            }else
            {
                if(t1<=a+t)
                    ans=(double)(t1-a)/(b-a);else
                if(t1>a+t && t1<b)
                    ans=(double)t/(b-a);else
                    ans=(double)(b-(t1-t))/(b-a);
            }
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
