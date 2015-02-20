#include <stdio.h>
int q[10];
int main()
{
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;++cas)
	{
		int i,j,n,m,num=0,k=0;
		char op[10];
		printf("Case %d:\n",cas);
		scanf("%d%d",&n,&m);
		for(i=0;i<m;++i)
		{
			scanf("%s",op);
			switch(op[4])
			{
				case 'L':
				scanf("%d",&num);
				if(k>=n)
					printf("The queue is full\n");else
				{
					printf("Pushed in left: %d\n",num);
					for(j=k-1;j>=0;--j)
						q[j+1]=q[j];
					k++;
					q[0]=num;
				}
				break;
				case 'R':
				scanf("%d",&num);
				if(k>=n)
					printf("The queue is full\n");else
				{
					printf("Pushed in right: %d\n",num);
					q[k]=num;
					k++;
				}
				break;
				case 'e':
				if(k<=0)
					printf("The queue is empty\n");else
				{
					printf("Popped from left: %d\n",q[0]);
					k--;
					for(j=0;j<k;++j)
						q[j]=q[j+1];
					q[k]=0;
				}
				break;
				case 'i':
				if(k<=0)
					printf("The queue is empty\n");else
				{
					printf("Popped from right: %d\n",q[k-1]);
					q[k-1]=0;
					k--;
				}
				break;
			}
		}
	}
	return 0;
}