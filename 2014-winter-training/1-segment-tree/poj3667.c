#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 50010
int flag[MAXN<<2],num[MAXN<<2],ls[MAXN<<2],rs[MAXN<<2];
int max(int a,int b)
{
	return a>b?a:b;
}
void pushup(int n,int m)
{
	ls[n]=ls[n<<1];
	rs[n]=rs[n<<1|1];
	if(ls[n]==(m>>1))
		ls[n]+=ls[n<<1|1];
	if(rs[n]==m-(m>>1))
		rs[n]+=rs[n<<1|1];
	num[n]=max(rs[n<<1]+ls[n<<1|1],max(num[n<<1],num[n<<1|1]));
}
void pushdown(int n,int m)
{
	if(flag[n]!=-1)
	{
		flag[n<<1]=flag[n<<1|1]=flag[n];
		flag[n]=-1;
	}
}
void build(int l,int r,int n)
{
	num[n]=ls[n]=rs[n]=r-l+1;
	flag[n]=-1;
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
		flag[n]=v;
		return;
	}
	int m=(l+r)>>1;
	if(L<=m)
		update(L,R,v,lson);
	if(m<R)
		update(L,R,v,rson);
	pushup(n,r-l+1);
}
int query(int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
}
int main()
{
	return 0;
}