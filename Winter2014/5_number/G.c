#include <cstdio>
using namespace std;
int com(int n,int k)
{
	int sum=n;
	for(int i=1;i<k;++i)
		sum*=(--n);
	while(k)
		sum/=(k--);
	return sum;
}
int div(int n)
{
	int num=0;
	for(int i=1;i<=n;++i)
		if(!(n%i))
			num++;
	return num;
}
int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		printf("%d\n",div(com(n,k)));
	}
	return 0;
}