#include<stdio.h>

_Bool prime[10000];
int num[5000];

int findprime()
{
	int i,j,k=0;
    prime[0] = 0;
    prime[1] = 0;
	for(i=2;i<10000;i++)
    	prime[i]=1;
    for (i=2; i<10000; i++)
        if (prime[i])
        {
        	num[k++]=i;
            for (j=i+i; j<10000; j+=i)
                prime[j] = 0;
        }
}

int main()
{
	int n,i,j,m,sum;
	findprime();
	while(scanf("%d",&n) && n!=0)
	{
		m=0;
		for(i=0;i<=n/2;i++)
		{
			for(j=i,sum=0;sum<n;j++)
				sum+=num[j];
			if(sum==n)
				m++;
		}
		printf("%d\n",m);
	}
	return 0;
}