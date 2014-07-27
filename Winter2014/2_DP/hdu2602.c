#include <stdio.h>
#include <string.h>
#define MAXN 1001
int nn[MAXN],vv[MAXN],f[MAXN];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int t,i,j,n,v;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&v);
		for(i=1;i<=n;++i)
			scanf("%d",&nn[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&vv[i]);
		for(i=1;i<=n;++i)
			for(j=v;j>=vv[i];--j)
				f[j]=max(f[j],f[j-vv[i]]+nn[i]);
		printf("%d\n",f[v]);
	}
	return 0;
}