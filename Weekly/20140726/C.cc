#include <cstdio>
using namespace std;
int main()
{
	int n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i]);
		a[i]=i^a[i-1];
	}
	return 0;
}