#include<stdio.h>

_Bool prime[1000000];

void findprime()
{
	long i,j;
    prime[0] = 0;
    prime[1] = 0;
	for(i=2;i<1000000;i++)
    	prime[i]=1;
    for (i=2; i<1000000; i++)
        if (prime[i])
            for (j=i+i; j<1000000; j+=i)
                prime[j] = 0;
}

int main()
{
	int a,d,n,i;
	long num;
	findprime();
	while(scanf("%d %d %d",&a,&d,&n)==3 && a!=0 && d!=0 && n!=0)
	{
		for(i=0,num=a;i<n;num+=d)
			if(prime[num])
				i++;
		printf("%ld\n",num-d);
	}
	return 0;
}