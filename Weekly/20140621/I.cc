#include <cstdio>
int main()
{
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
		{
			printf("%d %d\n",i,j);
			if(i==5)
				break;
		}
	return 0;
}