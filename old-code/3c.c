#include <stdio.h>
#include <stdlib.h>
int comp ( const void *a, const void *b )
{
    return * ( int * ) a - * ( int * ) b;
}
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
			if(l%2!=0 && pos[k]>l/2)
				dis[k]--;
		}
		qsort(pos,n,sizeof(int),comp);
		qsort(dis,n,sizeof(int),comp);
		min=l/2-dis[0];
		max=pos[0]<l-pos[n-1]?l-pos[0]:pos[n-1];
		printf("%d %d\n",min,max);
	}
	return 0;
}