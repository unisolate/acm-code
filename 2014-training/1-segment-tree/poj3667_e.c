#include <stdio.h>
#include <string.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define maxn 50010

int lsum[maxn<<2],rsum[maxn<<2],sum[maxn<<2],cover[maxn<<2];

int max(int a,int b)
{
	return a>b?a:b;
}

void pushUp(int n,int m)
{
	lsum[n]=lsum[n<<1];
	rsum[n]=rsum[n<<1|1];
	if(lsum[n]==m-(m>>1))
		lsum[n]+=lsum[n<<1|1];
	if(rsum[n]==(m>>1))
		rsum[n]+=rsum[n<<1];
	sum[n]=max(lsum[n<<1|1]+rsum[n<<1],max(sum[n<<1],sum[n<<1|1]));
}

void pushDown(int n,int m)
{
	if(cover[n]!=-1)
	{
		cover[n<<1]=cover[n<<1|1]=cover[n];
		sum[n<<1]=lsum[n<<1]=rsum[n<<1]=cover[n]?0:m-(m>>1);
		sum[n<<1|1]=lsum[n<<1|1]=rsum[n<<1|1]=cover[n]?0:(m>>1);
		cover[n]=-1;
	}
}

void build(int l,int r,int n)
{
	sum[n]=lsum[n]=rsum[n]=r-l+1;
	cover[n]=-1;
	if(l==r)
		return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}

void update(int L,int R,int v,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		sum[n]=lsum[n]=rsum[n]=v?0:r-l+1;
		cover[n]=v;
		return;
	}
	pushDown(n,r-l+1);
	int m=(l+r)>>1;
	if(L<=m)
		update(L,R,v,lson);
	if(m<R)
		update(L,R,v,rson);
	pushUp(n,r-l+1);
}

int query(int d,int l,int r,int n)
{
	if(lsum[n]>=d)
		return l;
	pushDown(n,r-l+1);
	int m=(l+r)>>1;
	if(sum[n<<1]>=d)
		return query(d,lson);
	else if(rsum[n<<1]+lsum[n<<1|1]>=d)
		return m-rsum[n<<1]+1;
	return query(d,rson);
}

int main()
{
	int n,m,op,d,x;
	scanf("%d %d",&n,&m);
	build(1,n,1);
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&d);
			if(sum[1]<d)
				printf("0\n");
			else{
				x=query(d,1,n,1);
				printf("%d\n",x);
				update(x,x+d-1,1,1,n,1);
			}
		}
		else{
			scanf("%d %d",&x,&d);
			update(x,x+d,0,1,n,1);
		}
	}
	return 0;
}