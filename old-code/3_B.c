#include <stdio.h>
char ans[200000];
int main()
{
	int i=0;
	char temp;
	while(scanf("%c",&temp)!=EOF)
	{
		if(i==0)
		ans[i++]=temp;else
			if(temp==ans[i-1])
				ans[--i]='\0';else
				ans[i++]=temp;
	}
	printf("%s",ans);
	return 0;
}