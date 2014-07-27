#include <stdio.h>
long long ans[51];
int main()
{
	int n=3;
	ans[1]=1;
	ans[2]=2;
	while(n<51)
		ans[n++]=ans[n-1]+ans[n-2];
	while(~scanf("%d",&n))
	{
		printf("%I64d\n",ans[n]);
	}
	return 0;
}