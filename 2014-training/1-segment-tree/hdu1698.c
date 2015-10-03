#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 100010
int num[MAXN<<2],add[MAXN<<2];
void pushUp(int n)
{
	num[n]=num[n<<1]+num[n<<1|1];
}
void pushDown(int n,int m)
{
	if(add[n])
	{
		add[n<<1]=add[n];
		add[n<<1|1]=add[n];
		num[n<<1]=add[n]*(m-(m>>1));
		num[n<<1|1]=add[n]*(m>>1);
		add[n]=0;
	}
}
void build(int l,int r,int n)
{
	add[n]=0;
	if(l==r)
	{
		num[n]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushUp(n);
}
void update(int L,int R,int v,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		add[n]=v;
		num[n]=v*(r-l+1);
		return;
	}
	pushDown(n,r-l+1);
	int m=(l+r)>>1;
	if(L<=m)
		update(L,R,v,lson);
	if(m<R)
		update(L,R,v,rson);
	pushUp(n);
}
int main()
{
	int t,tt,n,op,l,r,v;
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{
		scanf("%d%d",&n,&op);
		build(1,n,1);
		while(op--)
		{
			scanf("%d%d%d",&l,&r,&v);
			update(l,r,v,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",tt,num[1]);
	}
	return 0;
}