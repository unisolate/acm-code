#include <stdio.h>
#include <string.h>
#define INF 1<<30
int d[101],f[101][101][101];
int min(int a,int b)
{
	return a<b?a:b;
}
int dp(int i,int j,int k)
{
	if(i==j)
		return d[i]*(k-1);
	if(i>j)
		return 0;
	if(f[i][j][k]!=-1)
		return f[i][j][k];
	int n;
	f[i][j][k]=INF;
	for(n=i;n<=j;++n)
		f[i][j][k]=min(f[i][j][k],dp(i+1,n,k)+dp(n+1,j,k-i+n+1)+d[i]*(k-i+n-1));
	return f[i][j][k];
}
int main()
{
	int t,a,n,i;
	scanf("%d",&t);
	for(a=1;a<=t;++a)
	{
		memset(f,-1,sizeof(f));
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&d[i]);
		dp(1,n,1);
		printf("Case #%d: %d\n",a,f[1][n][1]);
	}
	return 0;
}