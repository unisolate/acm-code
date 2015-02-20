#include <stdio.h>
int main()
{
	int t,i,n,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&l,&r);
		long long sum=0;
		for(i=l;i<=r;++i)
		{
			sum+=(int)(n/i);
		}
		printf("%lld\n",sum);
	}
	return 0;
}