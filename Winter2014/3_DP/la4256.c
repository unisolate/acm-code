#include <stdio.h>
#include <string.h>
int path[201],link[101][101],d[201][101];
int min(int a,int b)
{
	return a<b?a:b;
}
int dp(int i,int j)
{
	if(i<=0)
		return 0;
	if(d[i][j])
		return d[i][j];
	d[i][j]=dp(i-1,j);
	int p=0;
	while(link[j][p])
	{
		d[i][j]=min(d[i][j],dp(i-1,link[j][p]));
		p++;
	}
	if(path[i]!=j)
		d[i][j]++;
	return d[i][j];
}
int main()
{
	int t,i,n,a,b,p,x,y;
	scanf("%d",&t);
	while(t--)
	{
		memset(d,0,sizeof(d));
		memset(link,0,sizeof(link));
		scanf("%d%d",&a,&b);
		for(i=0;i<b;++i)
		{
			scanf("%d%d",&x,&y);
			p=0;
			while(link[x][p])
				p++;
			link[x][p]=y;
			p=0;
			while(link[y][p])
				p++;
			link[y][p]=x;
		}
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&path[i]);
		printf("%d\n",dp(n,path[n]));
	}
	return 0;
}