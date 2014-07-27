#include<stdio.h>
/*int main()
{
    int t,i;
    float a1,b1,c1,a2,b2,c2;
    scanf("%d",&t);
    int ans[t];
    float x[t],y[t];
    for(i=0;i<t;i++)
    {
        scanf("%f %f %f %f %f %f",&a1,&b1,&c1,&a2,&b2,&c2);
        if(a1!=0)
        {
            if(a1*b2!=a2*b1)
            {
                ans[i]=0;
                x[i]=(c1*b2-c2*b1)/(a1*b2-a2*b1);
                y[i]=(c1*a2-c2*a1)/(b1*a2-b2*a1);
                /*if(c1==0 && c2==0)
                {

                    x=0;y=0;
                    printf("%.2f %.2f\n",x,y);
                }else
                {
                    x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
                    y=(c1*a2-c2*a1)/(b1*a2-b2*a1);
                    printf("%.2f %.2f\n",x,y);
                }
            }else
            if(a1*c2!=a2*c1)
                ans[i]=1;else
                ans[i]=2;
        }else
        {
            if(b1!=0)
            {
                if(a2!=0)
                {
                    x[i]=(c2-c1*b2/b1)/a2;
                    y[i]=c1/b1;
                }else
                {
                    if(b1*c2!=b2*c1)
                        ans[i]=1;else
                        ans[i]=2;
                }
            }else
            {
                if(c1!=0)
                    ans[i]=1;else
                    ans[i]=2;
            }
        }
    }
    for(i=0;i<t;i++)
    {
        if(ans[i]==1)
            printf("No solution\n");
        if(ans[i]==2)
            printf("Infinite\n");
        if(ans[i]==0)
            printf("%.2f %.2f\n",x[i],y[i]);
    }
    return 0;
}*/
int main()
{
    int t,i;
    double x,y,a1,b1,c1,a2,b2,c2;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&a1,&b1,&c1,&a2,&b2,&c2);
        if(a1!=0)
        {
            if(b2-a2*b1/a1!=0)
            {
                x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
                y=(a2*c1/a1-c2)/(a2*b1/a1-b2);
                printf("%.2f %.2f\n",x,y);
            }else
            if(a2*c1/a1-c2!=0)
                printf("No solution\n");else
                printf("Infinite\n");
        }else
        {
            if(b1!=0)
            {
                if(a2!=0)
                {
                    x=-(c1*b2/b1-c2)/a2;
                    y=c1/b1;
                    printf("%.2lf %.2lf\n",x,y);
                }else
                {
                    if(c1*b2/b1-c2!=0)
                        printf("No solution\n");else
                        printf("Infinite\n");
                }
            }else
            {
                if(c1!=0)
                    printf("No solution\n");else
                    printf("Infinite\n");
            }
        }
    }
    return 0;
}
