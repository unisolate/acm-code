#include <stdio.h>

int main()
{
	int t,i,j,a,n,m,k,c;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		c=0;
		scanf("%d %d %d",&n,&m,&k);
		int p[k][2];
		for(j=0;j<k;j++)
		{
			scanf("%d %d",&p[j][0],&p[j][1]);
			for(a=0;a<j;a++)
			{
				if((p[j][0]>p[a][0]&&p[j][1]<p[a][1])||(p[j][0]<p[a][0]&&p[j][1]>p[a][1]))
					c++;
			}
		}
		printf("Test case %d: %d\n",i+1,c);
	}
	return 0;
}