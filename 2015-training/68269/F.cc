#include <cstdio>
#include <algorithm>
using namespace std;
int a[1001],b[1001];
int main()
{
	int n,m,x=0,y=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
		scanf("%d",&a[i]),b[i]=a[i];
	sort(a,a+m);
	int p=0;
	for(int i=0;i<n;++i){
		if(a[p]<=0) ++p;
		y+=a[p];
		--a[p];
	}
	for(int i=0;i<n;++i){
		sort(b,b+m);
		x+=b[m-1];
		--b[m-1];
	}
	printf("%d %d",x,y);
	return 0;
}