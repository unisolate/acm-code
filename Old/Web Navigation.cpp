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
				backward.push(line);
				current=line;
				cout<<current;
				break;
			case 'B':
				if(backward.empty())
				{
					forward.push(current);
					current=backward.top();
					cout<<backward.top()<<" ";
					backward.pop();
				}else
				cout<<"Ignore";
				break;
			case 'F':
				if(forward.empty())
				{
					backward.push(current);
					current=forward.top();
					cout<<forward.top()<<" ";
					forward.pop();
				}else
				cout<<"Ignore";
				break;
		}
	}
	return 0;
}