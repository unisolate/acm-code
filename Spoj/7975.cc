#include <cstdio>
#include <cstring>
#include <algorithm>
int n,t[111111][3],d[111111][3];
int dp(int i,int j)
{
	if(i==n-1)
		return 0;
	if(j<0||j>3)
		return 0x3f3f3f3f;
	if(d[i][j])
		return d[i][j];
	int ans=0x3f3f3f3f;
	for(int k=0;k<3;++k)
		ans=std::min(ans,t[i][j]+dp(i+1,j-1+k));
	return d[i][j]=ans;
}
int main()
{
	int k=1;
	while(scanf("%d",&n)&&n)
	{
		memset(d,0,sizeof(d));
		int ans=0;
		for(int i=0;i<n;++i)
			scanf("%d%d%d",&t[i][0],&t[i][1],&t[i][2]);
		ans+=dp(0,1)+t[n-1][1];
		printf("%d. %d\n",k++,ans);
	}
	return 0;
}