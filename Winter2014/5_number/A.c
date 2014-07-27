#include <cstdio>
#include <cstring>
#define MAXN 10010
using namespace std;
int k[MAXN],p[MAXN];
bool prime[MAXN];
void findprime()
{
    for (int i=0; i<MAXN; i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for (int i=2; i<MAXN; i++)
        if (prime[i])
            for (int j=i*i; j<MAXN; j+=i)
                prime[j] = false;
    int pos=0;
    for(int i=1;i<MAXN;++i)
    	if(prime[i])
    		p[pos++]=i;
}
void run()
{
	int i,j;
	for(i=0;i<MAXN;++i)
	{
		int sum=p[i];
		j=i+1;
		while(sum<MAXN)
		{
			k[sum]++;
			sum+=p[j];
			j++;
		}
	}
}
int main()
{
	int num;
	memset(k,0,sizeof(k));
	findprime();
	run();
	while(scanf("%d",&num)&&num)
	{
		printf("%d\n",k[num]);
	}
	return 0;
}