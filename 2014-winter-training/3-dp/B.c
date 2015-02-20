#include <stdio.h>
#include <string.h>
#define INF 10000000
char l[101];
int f[101][101],p[101][101];
int min(int a,int b)
{
	return a<b?a:b;
}
int dp(int i,int j)
{
	if(i>j)
		return 0;
	if(f[i][j]!=-1)
		return f[i][j];
	int k,n;
	f[i][j]=INF;
	if((l[i]=='('&&l[j]==')')||(l[i]=='['&&l[j]==']'))
	{
		if(f[i][j]>dp(i+1,j-1))
		{
			f[i][j]=dp(i+1,j-1);
			p[i][j]=-2;
		}
	}
	if(l[i]=='('||l[i]=='[')
	{
		if(f[i][j]>dp(i+1,j)+1)
		{
			f[i][j]=dp(i+1,j)+1;
			p[i][j]=-3;
		}
	}
	if(l[j]==')'||l[j]==']')
	{
		if(f[i][j]>dp(i,j-1)+1)
		{
			f[i][j]=dp(i,j-1)+1;
			p[i][j]=-4;
		}
	}
	for(k=i;k<j;++k)
	{
		n=dp(i,k)+dp(k+1,j);
		if(f[i][j]>n)
		{
			f[i][j]=n;
			p[i][j]=k;
		}
	}
	return f[i][j];
}
void print(int i,int j)
{
	if(i>j)
		return;
	if(i==j)
	{
		if(l[i]=='('||l[i]==')')
			printf("()");
		else printf("[]");
		return;
	}
	if(p[i][j]==-2)
	{
		printf("%c",l[i]);
		print(i+1,j-1);
		printf("%c",l[j]);
		return;
	}
	if(p[i][j]==-3)
	{
		if(l[i]=='(')
			printf("()");
		else printf("[]");
		print(i+1,j);
		return;
	}
	if(p[i][j]==-4)
	{
		print(i,j-1);
		if(l[j]==')')
			printf("()");
		else printf("[]");
		return;
	}
	print(i,p[i][j]);
	print(p[i][j]+1,j);
}
int main()
{
	memset(f,-1,sizeof(f));
	memset(p,-1,sizeof(p));
	scanf("%s",l);
	int i,len=strlen(l);
	for(i=0;i<len;++i)
	{
		f[i][i]=1;
		p[i][i]=i;
	}
	dp(0,len-1);
	// printf("%d\n",f[0][len-1]);
	print(0,len-1);
	printf("\n");
	return 0;
}