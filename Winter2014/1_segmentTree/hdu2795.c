#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 200001
int h,w,k,v,num[MAXN<<2];
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
		num[n]=w;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushUp(n);
}
int query(int v,int l,int r,int n)
{
	if(l==r)
	{
		num[n]-=v;
		return l;
	}
	int m=(l+r)>>1;
	int ans=num[n<<1]>=v?query(v,lson):query(v,rson);
	pushUp(n);
	return ans;
}
int main()
{
	while(~scanf("%d %d %d",&h,&w,&k))
	{
		build(1,k,1);
		int i=k;
		while(i--)
		{
			scanf("%d",&v);
			if(num[1]<v)
				printf("-1\n");
			else
			{
				int ans=query(v,1,k,1);
				if(ans>h)
					printf("-1\n");
				else printf("%d\n",ans);
			}
		}
	}
	return 0;
}