#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define maxn 50010
int sum[maxn<<2];

void pushUp(int n)
{
	sum[n]=sum[n<<1]+sum[n<<1|1];
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
	pushUp(n);
}

void update(int x,int v,int l,int r,int n)
{
	if(l==r)
	{
		sum[n]+=v;
		return;
	}
	int m=(l+r)>>1;
	if(x<=m) //Very Important
		update(x,v,lson);
	else update(x,v,rson);
	pushUp(n);
}

int query(int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		return sum[n];
	}
	int ans=0,m=(l+r)>>1;
	if(L<=m)
		ans+=query(L,R,lson);
	if(m<R)
		ans+=query(L,R,rson);
	return ans;
}

int main()
{
	int t,i,a,b,n;
	char op[10];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case %d:\n",i);
		scanf("%d",&n);
		build(1,n,1);
		while(scanf("%s",op)&&op[0]!='E')
		{
			scanf("%d %d",&a,&b);
			switch(op[0])
			{
				case 'A':
				update(a,b,1,n,1);
				break;
				case 'S':
				update(a,-b,1,n,1);
				break;
				case 'Q':
				printf("%d\n",query(a,b,1,n,1));
				break;
			}
		}
	}
	return 0;
}