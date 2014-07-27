#include <stdio.h>
#include <string.h>
int f[60001];
int price[6] = {1,2,3,4,5,6};
int main()
{
	int n[6],i,j,k,a=1;
	while(scanf("%d%d%d%d%d%d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5])&&(n[0]||n[1]||n[2]||n[3]||n[4]||n[5]))
	{
		printf("Collection #%d:\n",a++);
		memset(f,0,sizeof(f));
		f[0]=1;
		int sum=0;
		for(i=0;i<6;i++)
		{
			printf("Ni is %d\n",n[i]);
			sum+=price[i]*n[i];
		}
		if(sum%2)
		{
			printf("Can't be divided.\n");
			continue;
		}
		int half=sum/2;
		for(i=0;i<6;++i)
			for(k=0;k<price[i];++k)
			{
				int left=n[i];
				for(j=k;j<=half;j+=price[i])
					if(f[j])
						left=n[i];
					else if(left>0)
					{
						left--;
						f[j]=1;
						printf("f%d changed.\n",j);
					}
			}
		if(f[half])
			printf("Can be divided.\n");
		else printf("Can't be divided.\n");
	}
	return 0;
}

for(int i=0;i<6;++i)
	for(int j=0;j<=tot;++j)
	{
		v=i+1;
		if(dp[j]>=0)
			dp[j]=n[i];
		else if(j<v||dp[j-v]<=0)
			dp[j]=-1;
		else dp[j]=dp[j-v]-1;
	}