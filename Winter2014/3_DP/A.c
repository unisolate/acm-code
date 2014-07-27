#include <stdio.h>
#include <string.h>
#define INF 1000000
int f[101][101],s[101][101];
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n,i,j,k;
	while(~scanf("%d",&n))
	{
		memset(f,-1,sizeof(f));
		memset(s,-1,sizeof(s));
		int c[n+1];
		for(i=1;i<=n;++i)
		{
			scanf("%d",&c[i]);
			f[i][i]=0;
			s[i][i]=c[i];
		}
		for(i=1;i<n;++i)
		{
			f[i][i+1]=c[i]*c[i+1];
			s[i][i+1]=(c[i]+c[i+1])%100;
		}
		dp(1,n);
		printf("%d\n",f[1][n]);
	}
	return 0;
}
int dp(int i,int j)
{
	int k;
	if(f[i][j]!=-1)
		return f[i][j];
	f[i][j]=INF;
	for(k=i;k<j;k++)
		f[i][j]=min(f[i][j],dp(i,k)+dp(k+1,j)+sum(i,k)*sum(k+1,j));
	return f[i][j];
}
int sum(int i,int j)
{
	if(s[i][j]!=-1)
		return s[i][j];
	return s[i][j]=(sum(i,j-1)+sum(j,j))%100;
}