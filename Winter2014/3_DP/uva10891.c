#include <stdio.h>
int num[101];
int main()
{
	int n,i,a,b;
	while(scanf("%d",&n) && n)
	{
		a=0;b=0;
		for(i=0;i<n;++i)
			scanf("%d",&num[i]);
		printf("%d\n",a-b);
	}
	return 0;
}