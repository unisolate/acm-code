#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    for(n=1;n<=1000;n++)
    {
        long a,b;
        //char rate;
        scanf("%ld",&a);
        //scanf("%c",&rate);
        scanf("%ld",&b);
        //int a=(rate[0]-48),b=(rate[2]-48);
        printf("%ld %ld\n",a,b);
        if(a==0 && b==0)
            break;
        double x,y,m,d,alpha,ba;
        d=sqrt((a*a+b*b));
        //alpha=atan(b/a);
        ba=b/a;
        printf("%.2f %.2lf\n",d,atan(ba));
        m=200/(d*alpha+a);
        x=a*m;
        y=b*m;
        printf("Case %d: %.2f %.2f\n",n,x,y);
    }
    return 0;
}
