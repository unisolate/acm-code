#include <cstdio>
#include <algorithm>
using namespace std;
struct vase
{
	int val,v;
}c[101][101];
int cmp(struct vase a,struct vase b)
{
	return a.val>b.val;
}
int main()
{
	int f,v,i,j;
	scanf("%d%d",&f,&v);
	for(i=0;i<=f;++i)
	{
		c[i][0].val=0;
		for(j=1;j<=v;++j)
		{
			c[i][j].v=j;
			scanf("%d",&c[i][j].val);
		}
	}
	for()
	printf("%d\n");
	return 0;
}