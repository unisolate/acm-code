#include <stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double a=100*(double)1/n;
		printf("%4.2f%%\n",a);
	}
	return 0;
}