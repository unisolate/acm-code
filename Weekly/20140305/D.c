#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 1000001
int sum[MAXN<<2],flag[MAXN<<2];
void pushup(int n)
{
	sum[n]=sum[n<<1]+sum[n<<1|1];
}
void pushdown(int n,int k)
{
	if(flag[n])
	{
		if(flag[n]>=4)
		{
			sum[n<<1]^=k;
		}
		flag[n<<1]+=flag[n];

	}
	return;
}
void build(int l,int r,int n)
{
	if(l==r)
	{
		scanf("%d",&sum[n]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(n);
}
void update(int op,int k,int L,int R,int l,int r,int n)
{
	if(l==r)
	{
		if(l>=L&&l<=R)
			if(op==1)
				sum[n]=sum[n]&k;
			else if(op==2)
				sum[n]=sum[n]|k;
			else if(op==3)
				sum[n]=sum[n]^k;
		return;
	}
	int m=(l+r)>>1;
	update(op,k,L,R,lson);
	update(op,k,L,R,rson);
	pushup(n);
}
void update(int op,int k,int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		flag[n]+=op;

		return;
	}
	pushdown(n);
	int m=(l+r)>>1;
	if(L<=m)
		update(op,k,L,R,lson);
	if(m<R)
		update(op,k,L,R,rson);
	pushup(n);
}
int query(int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		return sum[n];
	}
	pushdown(n);
	int m=(l+r)>>1,sum=0;
	if(L<=m)
		sum+=query(L,R,lson);
	if(m<R)
		sum+=query(L,R,rson);
	return sum;
}
int main()
{
	int t;
	char op[5];
	scanf("%d",&t);
	while(t--)
	{
		int n,m,l,r,k;
		scanf("%d%d",&n,&m);
		build(1,n,1);
		while(m--)
		{
			scanf("%s",op);
			switch(op[0])
			{
				case 'A':
					scanf("%d%d%d",&k,&l,&r);
					update(1,k,l+1,r+1,1,n,1);
					break;
				case 'O':
					scanf("%d%d%d",&k,&l,&r);
					update(2,k,l+1,r+1,1,n,1);
					break;
				case 'X':
					scanf("%d%d%d",&k,&l,&r);
					update(4,k,l+1,r+1,1,n,1);
					break;
				case 'S':
					scanf("%d%d",&l,&r);
					printf("%d\n",query(l+1,r+1,1,n,1));
					break;
			}
		}
	}
	return 0;
}