#include <stdio.h>
#include <string.h>
#define INF 1<<30
char a[100],b[100];
int s[100][100];
int min(int a,int b)
{
	return a<b?a:b;
}
int dp(int i,int j)
{
	if(i>j)
		return 0;
	if(i==j)
		return 1;
	if(s[i][j]!=-1)
		return s[i][j];
	int n;
	s[i][j]=dp(i+1,j)+1;
	for(n=i;n<=j;++n)
		if(a[i]==a[n])
			s[i][j]=min(s[i][j],dp(i,n)+dp(n+1,j));
	return s[i][j];
} 
int main()
{
	while(~scanf("%s %s",a,b))
	{
		memset(s,-1,sizeof(s));
		dp(0,strlen(a)-1);
		printf("%d\n",s[0][strlen(a)-1]);
	}
	return 0;
}