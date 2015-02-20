#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define maxn 200010

int num[maxn<<2];

int max(int a,int b)
{
	return a>b?a:b;
}

void pushUp(int n)
{
	num[n]=max(num[n<<1],num[n<<1|1]);
}

void build(int l,int r,int n)
{
	if(l==r)
	{
		scanf("%d",&num[n]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushUp(n);
}

void update(int x,int v,int l,int r,int n)
{
	if(l==r)
	{
		num[n]=v;
		return;
	}
	int m=(l+r)>>1;
	if(x<=m)
		update(x,v,lson);
	else update(x,v,rson);
	pushUp(n);
}

int query(int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
		return num[n];
	int ans=0,m=(l+r)>>1;
	if(L<=m)
		ans=max(ans,query(L,R,lson));
	if(m<R)
		ans=max(ans,query(L,R,rson));
	return ans;
}

int main()
{
	int n,m,a,b;
	char op[2];
	while(~scanf("%d%d",&n,&m))
	{
		build(1,n,1);
		while(m--)
		{
			scanf("%s%d%d",op,&a,&b);
			if(op[0]=='Q')
				printf("%d\n",query(a,b,1,n,1));
			else update(a,b,1,n,1);
		}
	}
	return 0;
}