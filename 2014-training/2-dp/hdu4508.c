#include <stdio.h>
#include <string.h>
int a[101],b[101],f[100001];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,m,i,j;
	while(~scanf("%d",&n))
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
			scanf("%d %d",&a[i],&b[i]);
		scanf("%d",&m);
		for(i=1;i<=n;i++)
			for(j=b[i];j<=m;j++)
				f[j]=max(f[j],f[j-b[i]]+a[i]);
		printf("%d\n",f[m]);
	}
	return 0;
} 