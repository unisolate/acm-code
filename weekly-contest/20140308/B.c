#include <stdio.h>
int main()
{
	char p[11][11];
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			scanf("%c",&p[i][j]);
	
	return 0;
}