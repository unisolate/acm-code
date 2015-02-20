#include <stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int l,n,k,min,max;
		scanf("%d %d",&l,&n);
		int pos[n],dis[n];
		for(k=0;k<n;k++)
		{
			scanf("%d",&pos[k]);
			dis[k]=l/2-pos[k]>0?l/2-pos[k]:pos[k]-l/2;
		}
		sort(pos,);
		min=l/2-dis[0];
		max=;
		printf("%d %d\n",min,max);
	}
	return 0;
}