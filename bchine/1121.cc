#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int l,w,h;
	while(scanf("%d%d%d",&l,&w,&h)&&l+w+h)
	{
		int n[5][5][5],sum=0;
		for(int i=0;i<l;++i)
		{
			for(int j=0;j<w;++j)
			{
				for(int k=0;k<h;++k)
				{
					cin>>n[i][j][k];
				}
			}
		}
	}
	return 0;
}