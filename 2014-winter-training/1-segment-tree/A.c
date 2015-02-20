#include <stdio.h>
#include <string.h>
int c[50001];
int n;
void update(int i,int v)
{
	for(;i<=n+1;i+=(i&-i))
		c[i]+=v;
}
int read(int i)
{
	int sum=0;
	for(;i>0;i-=(i&-i))
		sum+=c[i];
	return sum;
}
int main()
{
	int t,i,j,a,x;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		printf("Case %d:\n",i+1);
		char com[5];
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			update(j+1,a);
		}
		while(scanf("%s",com)&&com[0]!='E')
		{
			switch(com[0])
			{
				case 'A':
				scanf("%d %d",&x,&a);
				update(x,a);
				break;
				case 'S':
				scanf("%d %d",&x,&a);
				update(x,-a);
				break;
				case 'Q':
				scanf("%d %d",&x,&a);
				printf("%d\n",read(a)-read(x-1));
				break;
			}
		}
	}
	return 0;
}