#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 100010
int pos,s[MAXN<<2];
void pushup(int n)
{
	s[n]=s[n<<1]+s[n<<1|1];
}
void build(int l,int r,int n)
{
	if(l==r)
	{
		s[n]=0;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(n);
}
void update(int x,int l,int r,int n)
{
	if(l==r)
	{
		s[n]!=s[n];
		return;
	}
	int m=(l+r)>>1;
	if(x<=m)
		update(x,lson);
	else update(x,rson);
	pushup(n);
}
int query(int l,int r,int n)
{
	if()
}
int main()
{
	int t,l,c=1,n,op,a;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		pos=0;
		scanf("%d %d",&l,&n);
		build(1,l,1);
		while(n--)
		{
			scanf("%d",&a);
			if(!a)
			{
				scanf("%d",&x);
				update(x,1,n,1);
			}
			else{
				ans+=query(pos,1,n,1)
				update(x,1,n,1);
			}
		}
		printf("Case %d: %d\n",c++,ans);
	}
	return 0;
}