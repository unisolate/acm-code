#include <bits/stdc++.h>
#define MAXN 1010
struct point
{
	int x,b;
}m[MAXN];
int cmp(struct point a, struct point b)
{
    return a.x < b.x;
}
int main()
{
	int n,v,p,i;
	while(~scanf("%d%d%d",&n,&v,&p))
	{
		for(i=0;i<n;++i)
			scanf("%d%d",m[i].x,m[i].b);
		sort(m,m+n,cmp);
		dp();
	}
	return 0;
}