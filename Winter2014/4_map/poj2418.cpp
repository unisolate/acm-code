#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int> m;
	char line[50];
	int sum=0;
	while(gets(line)!=NULL)
	{
		if(m.find(line)!=m.end())
			m[line]++;
		else m[line]=1;
		sum++;
	}
	map<string,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<" ";
		cout<<fixed<<setprecision(4);
		cout<<it->second/(double)sum*100<<endl;
	}
	return 0;
}