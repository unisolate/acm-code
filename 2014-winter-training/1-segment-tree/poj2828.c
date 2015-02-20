#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 200001
int num[MAXN<<2],ans[MAXN],val[MAXN],pos[MAXN];
void build(int l,int r,int n)
{
	num[n]=r-l+1;
	if(l==r)
	{
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
int query(int p,int l,int r,int n)
{
	num[n]--;
	if(l==r)
	{
		return l;
	}
	int m=(l+r)>>1;
	if(num[n<<1]<p)
	{
		p-=num[n<<1];
		return query(p,rson);
	}else return query(p,lson);
}
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		build(1,n,1);
		for(i=0;i<n;++i)
			scanf("%d %d",&pos[i],&val[i]);
		for(i=n-1;i>=0;--i)
			ans[query(pos[i]+1,1,n,1)]=val[i];
		for(i=1;i<=n;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}