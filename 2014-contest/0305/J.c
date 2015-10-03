#include <stdio.h>
#include <string.h>
#include <algorithm>
char n[1010];
int pos;
int act()
{
	char minchar=n[pos];
	int minpos=pos;
	for(int i=pos+1;i<strlen(n);++i)
	{
		if(n[i]<=minchar)
		{
			if(!pos&&n[i]=='0')
				continue;else{
				minchar=n[i];
				minpos=i;
				}
			}
		}
	if(minpos==pos)
		return -1;
	char temp=n[pos];
	n[pos]=n[minpos];
	n[minpos]=temp;
	return pos;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%s%d",n,&m);
		pos=0;
		while(m--)
		{
			int haha;
			while(n[pos]=='1'||n[pos]=='0')
				pos++;
			if(pos>=strlen(n))
				break;
			while(act()==-1)
			{
				pos++;
				if(pos>=strlen(n))
					break;
			}
			pos++;
			if(pos>=strlen(n))
				break;
		}
		printf("%s\n",n);
	}
	return 0;
}