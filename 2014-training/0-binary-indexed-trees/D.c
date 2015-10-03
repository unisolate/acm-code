#include <stdio.h>
int main()
{
	int t,i,j,k,l,n,a;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		a=0;
		scanf("%d",&n);
		long p[n];
		for(j=0;j<n;j++)
		{
			scanf("%ld",&p[j]);
			for(k=0;k<j-1;k++)
			{
				for(l=k+1;l<j;l++)
				{
					if((p[l]<=p[k]&&p[l]>=p[j])||(p[l]>=p[k]&&p[l]<=p[j]))
						a++;
				}
			}
		}
		printf("%d\n",a);
	}
	return 0;
}