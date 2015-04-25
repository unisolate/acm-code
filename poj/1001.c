#include <stdio.h>
int main (void)
{
	int n,i;
	double r,ans;
	while(scanf("%lf %d",&r,&n)==2)
	{
		ans=1;
		for(i=0;i<n;i++)
			ans*=r;
		printf("%lf\n",ans);
	}
	return 0;
}
