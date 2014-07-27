#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x,i,j,num[n+1][n+1];
		num[1][1]=1;
		printf("%d\n",num[1][1]);
		for(i=2;i<=n;i++)
		{
			num[i][1]=1;
			printf("%d ",num[i][1]);
			for(j=2;j<=i-1;j++)
			{
				num[i][j]=num[i-1][j-1]+num[i-1][j];
				printf("%d ",num[i][j]);
			}
			num[i][i]=1;
			printf("%d\n",num[i][i]);
		}
		printf("\n");
	}
	return 0;
}