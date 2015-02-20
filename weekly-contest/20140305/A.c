#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXN 10000000
char a[MAXN],b[MAXN];
int main()
{
	int t,i,base;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%d",a,b,&base);
		int temp,alen=strlen(a),blen=strlen(b);
		long long aa=0,bb=0;!
		while(scanf("%c",&tem)&&tem!=' ')
		{
			
		}
		for(i=0;i<alen;++i)
		{
			char tem=a[alen-i-1];
			if(tem>='0'&&tem<='9')
				temp=tem-'0';else
				temp=tem-'a'+10;
			aa+=temp*(int)pow(base,i);
		}
		for(i=0;i<blen;++i)
		{
			char tem=b[blen-i-1];
			if(tem>='0'&&tem<='9')
				temp=tem-'0';else
				temp=tem-'a'+10;
			bb+=temp*(int)pow(base,i);
		}
		printf("(%lld,%lld)\n",aa/bb,aa%bb);
	}
	return 0;
}