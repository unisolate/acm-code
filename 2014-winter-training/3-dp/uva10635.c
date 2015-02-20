#include <stdio.h>
#include <string.h>
#define MAXN 62501
int num[MAXN],seq[MAXN],lis[MAXN];
int main()
{
	int t,cas, n,p,q, i, temp,pos,len;
	scanf("%d",&t);
	for(cas=1;cas<=t;++cas)
	{
		memset(num,sizeof(num),0);
		scanf("%d%d%d",&n,&p,&q);
		for(i=1;i<=p+1;++i)
		{
			scanf("%d",&temp);
			num[temp]=i;
		}
		pos=1;
		for(i=0;i<=q;++i)
		{
			scanf("%d",&temp);
			if(num[temp])
				seq[pos++]=num[temp];
		}

		len=1;
		lis[1]=seq[1];
		for(i=2;i<=pos;++i)
		{
			if(seq[i]>lis[len])
				lis[++len]=seq[i];
			else {
				int m,x=1,y=len;
				while(x<y)
				{
					m=(x+y)>>1;
					if(lis[m]>=seq[i])
						y=m;
					else x=m+1;
				}
				lis[x]=seq[i];
			}
		}
		printf("Case %d: %d\n",cas,len);
	}
	return 0;
}