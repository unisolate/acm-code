#include <stdio.h>
#include <string.h>
char x[1000],y[1000];
int r[1000][1000];
int max(int a,int b)
{
	return a>b?a:b;
}
int lcs(int m,int n)
{
	if(m<0||n<0)
		return 0;
	if(r[m][n]!=-1)
		return r[m][n];
	if(x[m]==y[n])
		r[m][n]=lcs(m-1,n-1)+1;
	else r[m][n]=max(lcs(m,n-1),lcs(m-1,n));
	return r[m][n];
}
int main()
{
	while(~scanf("%s %s",x,y))
	{
		memset(r,-1,sizeof(r));
		printf("%d\n",lcs(strlen(x)-1,strlen(y)-1));
	}
	return 0;
}