#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 10000001
int cover[MAXN<<2];
void pushUp(int n)
{
	 
}
void build(int l,int r,int n)
{
	if(l==r)
	{
		cover[n]=0;
		return;
	}
	build(lson);
	build(rson);
	pushUp(n);
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);

	}
	return 0;
}