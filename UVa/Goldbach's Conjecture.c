#include<stdio.h>
#include<string.h>

int main()
{
    int prime[10000],n,i,a=0,num;
    int isprime=1;
    memset(prime,0,sizeof(prime));

    primex(prime,10000);


    /*for(n=2;n<10000;n++)
    {
        for(i=2;i*i<=n;i++)
            if(n%i==0)
                isprime=0;

        if(isprime==1)
            prime[a++]=n;
        isprime=1;
    }
    */

    for(a=0;a<20000;a++)
       printf("%d\n",prime[a]);

    /*while(scanf("%ld",&num))
        for(n=0;n<sizeof(prime);n++)
            for(i=0;i<sizeof(prime);i++)
                if(prime[n]+prime[i]==num)
                    {
                        printf("%ld = %ld + %ld\n",num,n,i);
                        break;
                    }*/

    return 0;
}

/*int primex(int a[],int n)
{
    int i,j,k,x,num,*b;
    n++;
    n/=2;
    b=(int *)malloc(sizeof(int)*(n+1)*2);
    a[0]=2;a[1]=3;num=2;
    for(i=1;i<=2*n;i++)
        b[i]=0;
    for(i=3;i<=n;i+=3)
        for(j=0;j<2;j++)
            {
            x=2*(i+j)-1;
            while(b[x]==0)
                {
                a[num++]=x;
                for(k=x;k<=2*n;k+=x)
                    b[k]=1;
                }
            }
    return num;
}
*/
