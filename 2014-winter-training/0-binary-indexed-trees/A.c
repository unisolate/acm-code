#include <stdio.h>
#include <string.h>
int main()
{
	int flag, s, x,y,a, l,b,r,t;
	scanf("%d %d",&flag,&s);
	int table[s][s];
	memset(table,0,sizeof(table));
	while(scanf("%d",&flag) && flag!=3)
	{
		if(flag==1)
		{
			scanf("%d %d %d",&x,&y,&a);
			table[x][y]+=a;
		}
		if(flag==2)
		{
			scanf("%d %d %d %d",&l,&b,&r,&t);
			int i,j,sum=0;
			for(i=l;i<=r;i++)
				for(j=b;j<=t;j++)
					sum+=table[i][j];
			printf("%d\n",sum);
		}
	}
	return 0;
}