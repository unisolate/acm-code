#include <stdio.h>

#define lson l,m,n<<1
#define rson m+1,r,n<<1|1

long long sum[100001<<2],add[100001<<2];
 
void pushUp(int n)
{
	sum[n]=sum[n<<1]+sum[n<<1|1];
}

void pushDown(int n,int m)
{
	if(add[n])
	{
		add[n<<1]+=add[n];
		add[n<<1|1]+=add[n];
		sum[n<<1]+=add[n]*(m-(m>>1));
		sum[n<<1|1]+=add[n]*(m>>1);
		add[n]=0;
	}
}

void build(int l,int r,int n)
{
	add[n]=0;
	if(l==r)
	{
		scanf("%lld",&sum[n]);
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
		add[n]+=v;
		sum[n]+=(long long)v*(r-l+1);
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

long long query(int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		return sum[n];
	}
	pushDown(n,r-l+1);
	int m=(l+r)>>1;
	long long ans=0;
	if(L<=m)
		ans+=query(L,R,lson);
	if(m<R)
		ans+=query(L,R,rson);
	return ans;
}

int main()
{
	int n,q,a,b,c;
	char op;
	scanf("%d %d",&n,&q);
	build(1,n,1);
	while(q--)
	{
		getchar();
		scanf("%c %d %d",&op,&a,&b);
		if(op=='Q')
		{
			printf("%lld\n",query(a,b,1,n,1));
		}else
		{
			scanf("%d",&c);
			update(a,b,c,1,n,1);
		}
	}
	return 0;
}