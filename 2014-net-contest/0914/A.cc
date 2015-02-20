#include <cstdio>
#include <cstring>
using namespace std;
char s[222222];
int main()
{
	while(~scanf("%s",s))
	{
		bool f1=false,f2=false;
		int len=strlen(s);
		for(int i=0;i<len;++i)
		{
			if(i+4<len&&s[i]=='A'&&s[i+1]=='p'&&s[i+2]=='p'&&s[i+3]=='l'&&s[i+4]=='e')
				f1=true;
			else if(i+5<len&&s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='h'&&s[i+3]=='o'&&s[i+4]=='n'&&s[i+5]=='e')
				f1=true;
			else if(i+3<len&&s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='o'&&s[i+3]=='d')
				f1=true;
			else if(i+3<len&&s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='a'&&s[i+3]=='d')
				f1=true;
			if(i+3<len&&s[i]=='S'&&s[i+1]=='o'&&s[i+2]=='n'&&s[i+3]=='y')
				f2=true;
		}
		if(f1)
			printf("MAI MAI MAI!\n");
		if(f2)
			printf("SONY DAFA IS GOOD!\n");
	}
	return 0;
}