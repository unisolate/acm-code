#include <stdio.h>

#define lson l,m,n<<1
#define rson m+1,r,n<<1|1

int color[100001<<2];
_Bool cover[100001<<2];
int num;

void pushUp(int n)
{
	color[n]=color[n<<1]|color[n<<1|1];
}

void pushDown(int n)
{
	if(cover[n])
	{
		cover[n<<1]=1;
		cover[n<<1|1]=1;
		color[n<<1]=color[n];
		color[n<<1|1]=color[n];
		cover[n]=0;
	}
}

void build(int l,int r,int n)
{
	cover[n]=1;
	color[n]=1;
	if(l==r)
	{
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}

void update(int L,int R,int v,int l,int r,int n)
{
	if(L<=l&&r<=R)
	{
		cover[n]=1;
		color[n]=v;
		return;
	}
	pushDown(n);
	int m=(l+r)>>1;
	if(L<=m)
		update(L,R,v,lson);
	if(m<R)
		update(L,R,v,rson);
	pushUp(n);
}

void query(int L,int R,int l,int r,int n)
{
	if(cover[n])
	{
		num|=color[n];
		return;
	}//Very Important
	if(L<=l&&r<=R)
	{
		num|=color[n];
		return;
	}
	int m=(l+r)>>1;
	if(L<=m)
		query(L,R,lson);
	if(m<R)
		query(L,R,rson);
}

int get(int num)
{
	int ans=0;
	while(num)
	{
		if(num%2)
			ans++;
		num>>=1;
	}
	return ans;
}

void swap(int *x, int *y) {
	int temp=0;
	temp=*x;
	*x=*y;
	*y=temp;
} 

int main()
{
	int l,t,o,a,b,c;
	char op[2];
	scanf("%d %d %d",&l,&t,&o);
	build(1,l,1);
	while(o--)
	{
		scanf("%s",op);
		if(op[0]=='C')
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a>b)
				update(b,a,1<<(c-1),1,l,1);else
			update(a,b,1<<(c-1),1,l,1);
		}else
		{
			scanf("%d%d",&a,&b);
			num=0;
			if(a>b)
				query(b,a,1,l,1);else
			query(a,b,1,l,1);
			printf("%d\n",get(num));
		}
	}
	return 0;
}