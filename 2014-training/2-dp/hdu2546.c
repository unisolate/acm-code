#include <stdio.h>
#define MAXN 1001
int p[MAXN];
int main()
{
	int n,m,i;
	while(scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;++i)
			scanf("%d",p[i]);
		scanf("%d",&m);
	}
	return 0;
}