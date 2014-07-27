#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t,a,b,c;
	long long mi,ma;
	cin>>t;
	while(t--)
	{
		mi=0;
		ma=0;
		cin>>a>>b>>c;
		int n=a+b+c,aa=a,bb=b,cc=c;
		for(int i=0;i<n;++i)
		{
			if(cc)
			{
				ma+=50*(i*2+1);
				cc--;
			}
			else if(bb)
			{
				ma+=100*(i*2+1);
				bb--;
			}
			else if(aa)
			{
				ma+=300*(i*2+1);
				aa--;
			}
		}
		for(int i=0;i<n;++i)
		{
			if(a)
			{
				mi+=300*(i*2+1);
				a--;
			}
			else if(b)
			{
				mi+=100*(i*2+1);
				b--;
			}
			else if(c)
			{
				mi+=50*(i*2+1);
				c--;
			}
		}
		cout<<mi<<" "<<ma<<endl;
	}
	return 0;
}