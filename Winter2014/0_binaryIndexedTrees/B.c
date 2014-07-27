#include <stdio.h>
int main()
{
	int n=0,i=0,j=0,d=0;
	long long sum=0;
	scanf("%d",&n);
	int v[n],x[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&v[i],&x[i]);
		for(j=0;j<i;j++)
		{
			if(x[i]>x[j])
				d=x[i]-x[j];
			else d=x[j]-x[i];
			if(v[i]>v[j])
				sum+=d*v[i];
			else sum+=d*v[j];
		}
	}
	printf("%lld\n",sum);
	return 0;
}