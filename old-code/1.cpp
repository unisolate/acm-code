#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<string> forward;
	stack<string> backward;
	string line,current="http://www.acm.org/";
	while(cin>>line && line[0]!='Q')
	{
		switch(line[0])
		{
			case 'V':
				cin>>line;
				backward.push(current);
				current=line;
				cout<<current<<'\n';
				while(!forward.empty())
					forward.pop();
				break;
			case 'B':
				if(!backward.empty())
				{
					forward.push(current);
					cout<<backward.top()<<'\n';
					current=backward.top();
					backward.pop();
				}else
				cout<<"Ignored\n";
				break;
			case 'F':
				if(!forward.empty())
				{
					backward.push(current);
					cout<<forward.top()<<'\n';
					current=forward.top();
					forward.pop();
				}else
				cout<<"Ignored\n";
				break;
		}
	}
	return 0;
}