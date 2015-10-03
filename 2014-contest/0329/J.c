#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c[1001],m;
		cin>>n>>m;
		for(int i=0;i<n;++i)
		{
			cin>>c[i];
		}
		int maxx=0;
		for(int i=0;i<n;++i)
		{
			int temp=0,k;
			for(int j=i;j<i+m;++j)
			{
				k=j;
				if(k>=n)
				{
					k-=n;
				}
				temp+=c[k];
			}
			if(temp>maxx)
				maxx=temp;
		}
		cout<<maxx<<endl;
	}
	return 0;
}