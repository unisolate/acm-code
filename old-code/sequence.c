#include <stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long a,b,ans=0;
		scanf("%ld %ld",&a,&b);
		while(a%3!=1)
		{
			a++;
			ans++;
		}
		while(b%3!=1)
		{
			b--;
			ans++;
		}
		ans+=(b-a)/3*2;
		printf("Case %d: %ld\n",i+1,ans);
	}
	return 0;
}