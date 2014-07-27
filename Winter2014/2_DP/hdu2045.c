#include <stdio.h>
long long num[51];
int main()
{
	int n=4;
	num[1]=3;num[2]=6;num[3]=6;
	while(n<51)
	{
		num[n]=num[n-2]*2+num[n-1];
		n++;
	}
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",num[n]);
	return 0;
}