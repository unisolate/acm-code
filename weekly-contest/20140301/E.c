#include <stdio.h>
#include <string.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 100010
char line[MAXN];
int flag[MAXN<<2],sum[MAXN<<2],num[MAXN],k;
inline void pushdown(int n)
{
	if(flag[n]&&flag[n]%2)
	{
		flag[n<<1]++;
		flag[n<<1|1]++;
		flag[n]++;
	}
}
void build(int l,int r,int n)
{
	if(l==r)
	{
		sum[n]=num[k++];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void update(int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		flag[n]++;
		return;
	}
	pushdown(n);
	int m=(l+r)>>1;
	if(L<=m)
		update(L,R,lson);
	if(m<R)
		update(L,R,rson);
}
int query(int p,int l,int r,int n)
{
	if(l==r)
	{
		if(flag[n]%2)
			return !sum[n];
		else return sum[n];
	}
	pushdown(n);
	int m=(l+r)>>1;
	if(p<=m)
		return query(p,lson);
	else return query(p,rson);
}
int main()
{
	int t,cas,i,n,z,l,r;
	char op;
	scanf("%d",&t);
	for(cas=1;cas<=t;++cas)
	{
		k=0;
		memset(flag,0,sizeof(flag));
		printf("Case %d:\n",cas);
		scanf("%s",line);
		n=strlen(line);
		for(i=0;i<n;++i)
			num[i]=line[i]-'0';
		build(1,n,1);
		scanf("%d",&z);
		for(i=0;i<z;++i)
		{
			getchar();
			scanf("%c",&op);
			if(op=='I')
			{
				scanf("%d%d",&l,&r);
				update(l,r,1,n,1);
			}else
			{
				scanf("%d",&l);
				printf("%d\n",query(l,1,n,1));
			}
		}
	}
	return 0;
}