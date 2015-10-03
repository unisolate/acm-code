#include <stdio.h>
#include <string.h>
#define MAXN 200020
int c[MAXN],f[MAXN];
int main()
{
	memset(f,0,sizeof(f));
	int n,i,m,p,v,op;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&c[i]);
	scanf("%d",&m);
	for(i=0;i<m;++i)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&p,&v);
			while(v>0&&p<=n)
			{
				f[p]+=v;
				if(f[p]>c[p])
				{
					v=f[p]-c[p];
					f[p]=c[p];
					p++;
				}
				else v=0;
			}
		}else
		{
			scanf("%d",&p);
			printf("%d\n",f[p]);
		}
	}
	return 0;
}