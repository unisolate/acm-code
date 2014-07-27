#include <stdio.h>
int main()
{
	int n,k,m,i,d,ans;
	while(scanf("%d%d%d",&n,&k,&m) && n+k+m)
	{
		d=0;
		for(i=2;i<=n;++i)
		{
			d=(d+k)%i;
			printf("%d\n",d);
		}
		ans=(d+m-k+1)%n;
		if(ans<=0)
			ans+=n;
		printf("%d\n",ans);
	}
	return 0;
}