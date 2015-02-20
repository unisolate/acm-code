#include <stdio.h>
#include <string.h>

struct Node{
	int l,r,max;
}tree[600000];

int num[200001];

int max(int a,int b)
{
	return a>b?a:b;
}

int build(int l,int r,int n)
{
	tree[n].l=l;
	tree[n].r=r;
	if(l==r)
	{
		tree[n].max=num[l];
		return tree[n].max;
	}
	int m=(l+r)/2;
	tree[n].max=max(build(l,m,n*2),build(m+1,r,n*2+1));
	return tree[n].max;
}

void update(int i,int v,int n)
{
	if(v>tree[n].max)
		tree[n].max=v;
	if(tree[n].l==tree[n].r)
		return;
	int m=(tree[n].l+tree[n].r)/2;
	if(i<=m)
		update(i,v,2*n);
	else update(i,v,2*n+1);
}

int query(int l,int r,int n)
{
	if(tree[n].l>r||tree[n].r<l)
		return 0;
	if(tree[n].l>=l&&tree[n].r<=r)
		return tree[n].max;
	int m=(tree[n].l+tree[n].r)/2;
	return max(query(l,r,n*2),query(l,r,n*2+1));
}

int main()
{
	long n,i;
	int m,a,b;
	char flag;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(tree,0,sizeof(tree));
		memset(num,0,sizeof(num));
		for(i=1;i<=n;i++)
			scanf("%d",&num[i]);
		build(1,n,1);
		for(i=0;i<m;i++)
		{
			getchar();
			scanf("%c %d %d",&flag,&a,&b);
			if(flag=='Q')
				printf("%d\n",query(a,b,1));
			else
				update(a,b,1);
		}
	}
	return 0;
}