#include <cstdio>
#include <algorithm>
#define MAXN 2222
using namespace std;
int p[MAXN],r[MAXN];
int groups;
int cmp(int a,int b)
{
	return a>b;
}
void init()
{
	for(int i=0;i<MAXN;++i)
	{
		p[i]=i;
		r[i]=1;
	}
}
int fin(int x)
{
	return x==p[x]?x:(p[x]=fin(p[x]));
}
void uni(int y,int x)
{
	x=fin(x);
	y=fin(y);
	if(x==y)
		return;
	groups--;
	r[y]+=r[x];
	r[x]=0;
	p[x]=y;
}
int main()
{
	int n,x;
	groups=n;
	scanf("%d",&n);
	init();
	for(int i=0;i<n;++i)
	{
		scanf("%d",&x);
		if(x!=-1)
			uni(x,i);
	}
	sort(r,r+n,cmp);
	printf("%d\n",r[0]);
	return 0;
}
