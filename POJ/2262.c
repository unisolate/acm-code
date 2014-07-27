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
	long m,n;
	findprime();
	while(scanf("%ld",&n) && n!=0)
	{
		for(m=2;m<n;m++)
		{
			if(prime[m] && prime[n-m])
			{
				printf("%ld = %ld + %ld\n",n,m,n-m);
				break;
			}
		}
	}
	return 0;
}