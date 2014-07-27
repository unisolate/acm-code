#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char line[333];
	scanf("%s",line);
	int i,now=0,plus=0,minus=0;
	for(i=0;i<strlen(line);++i)
	{
		if(line[i]=='+')
			now++;else
			now--;
		plus=max(plus,now);
		minus=min(minus,now);
	}
	printf("%d\n",plus-minus);
	return 0;
}