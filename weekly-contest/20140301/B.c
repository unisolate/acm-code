#include <stdio.h>
int num[20];
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%d",&num[i]);
	}
	return 0;
}