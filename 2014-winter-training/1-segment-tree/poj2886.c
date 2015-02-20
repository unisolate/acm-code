#include <stdio.h>
#include <math.h>
#define MAXN 500001
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
char name[MAXN][10];
int count=1,a[MAXN],f[MAXN],ma[MAXN<<2];
int max(int a,int b)
{
	return a>b?a:b;
}
void factor(int n)
{
	if(f[n])
		return;
    int i,r,ans=2,s=sqrt(n);
    for(i=2;i<=s;++i)
        if(n%i==0)
            if(i==s)
            {
                r=n/i;
                if(r==i)
                    ans++;
                else
                	ans+=2;
            }else ans+=2;
    f[n]=ans;
}
void pushUp(int n)
{
	ma[n]=max(ma[n<<1],ma[n<<1|1]);
}
void build(int l,int r,int n)
{
	if(l==r)
	{
		ma[n]=f[count++];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushUp(n);
}
int query(int L,int R,int l,int r,int n)
{
	if(L<=l&&r<=R)
		return ma[n];
	int ans=0,m=(l+r)>>1;
	if(L<=m)
		ans=max(ans,query(L,R,lson));
	if(m<R)
		ans=max(ans,query(L,R,rson));
	return ans;
}
int main()
{
	int n,k,i;
	f[1]=1;f[2]=2;
	for(i=3;i<MAXN;++i)
		factor(i);
	build(1,MAXN,1);
	while(~scanf("%d%d",&n,&k))
	{
		char nn[10];
		int ans=query(1,n,1,MAXN,1);
		for(i=1;i<=n;++i)
			scanf("%s %d",name[i],&a[i]);
		for(i=0;i<n;++i)
		{
		}
		printf("%s %d\n",nn,ans);
	}
	return 0;
}