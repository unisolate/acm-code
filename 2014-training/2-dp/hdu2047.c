#include <stdio.h>
long long a[51],b[51];
int main()
{
	int n=2;
	a[1]=2;b[1]=1;
	while(n<51)
	{
		a[n]=2*(a[n-1]+b[n-1]);
		b[n]=a[n-1];
		n++;
	}
	while(~scanf("%d",&n))
	{
		printf("%I64d\n",a[n]+b[n]);
	}
	return 0;
}