#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int num[MAXN],rev[MAXN],lis[MAXN],ii[MAXN],dd[MAXN];
void getlis(int* num,int* ii,int n)
{
    int len, i, j;
    len = 0;
    for (i = 1; i <= n; ++i)
    {
        j = lower_bound(lis + 1, lis + len + 1, num[i]) - lis;
        lis[j] = num[i];
        len = max(len, j);
        ii[i]=len;
    }
}
int main()
{
	int n,i,ans,fin;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;++i)
		{
			scanf("%d",&num[i]);
			rev[n-i+1]=num[i];
		}
		ans=0,fin=-1;
		getlis(num,ii,n);
		getlis(rev,dd,n);
		for(i=1;i<=n;++i)
		{
			ans=min(ii[i],dd[n-i+1])*2-1;
			if(ans>fin)
				fin=ans;
		}
		printf("%d\n",fin);
	}
	return 0;
}