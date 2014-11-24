#include<stdio.h>
#include<string.h>
long p[100000];
int main()
{
    memset(p,100,sizeof(p));
    int t,x,q,a,b,c,time;
    long n,i,m;
    scanf("%d",&t);
    for(x=0;x<t;x++)
    {
        scanf("%ld %d %d %d %d",&n,&q,&a,&b,&c);
        for(m=1,p[0]=0;m<n;m++)
          p[m]=(a*p[m-1]+b)%c+1;
        //for(m=1;m<n;m++)
        //    printf("%d\n",p[m]);
        for(m=0;m<q;m++)
        {
            scanf("%ld",&i);
            for(time=1;i+p[i]<=n;time++)
            {
                //printf("%ld\n",i);
                i=i+p[i];
                if(i>n) 
                    break;
            }
            printf("%d %d\n",time,i);
        }
    }
    return 0;
}
