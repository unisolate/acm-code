#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int color[n+1];
	memset(color,0,sizeof(color));
	for(i=0;i<m;i++)
	{
		int a[3],used[4],k=1;
		memset(used,0,sizeof(used));
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
		for(j=0;j<3;j++)
			if(color[a[j]]!=0)
				used[color[a[j]]]=1;
		for(j=0;j<3;j++)
			if(color[a[j]]==0)
			{
				while(used[k]!=0)
					k++;
				color[a[j]]=k;
				k++;
			}
	}
	for(i=1;i<=n;i++)
		printf("%d ",color[i]);
	return 0;
}