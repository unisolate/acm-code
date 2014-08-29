/*
#include<iostream>
#include<map>
#include<string>
#define z map<string,int>
using namespace std;char s[50];int main(){z m;float k=0;while(gets(s))m[s]+=100,++k;for(z::iterator i=m.begin();i!=m.end();++i)cout<<i->first,printf(" %.4f\n",i->second/k);}

#include<cstdio>
#include<map>
#include<string>
#define z map<string,int>
using namespace std;char s[50];int main(){z m;float k=0;while(gets(s))m[s]+=100,++k;for(z::iterator i=m.begin();i!=m.end();++i)printf("%s %.4f\n",i->first.c_str(),i->second/k);}
*/
#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#define z map<string,int>
using namespace std;char s[50],k=0;int main(){z m;while(gets(s))++m[s],++k;for(z::iterator i=m.begin();i!=m.end();++i)cout<<i->first,printf(" %.4f\n",i->second*100.0/k);}
