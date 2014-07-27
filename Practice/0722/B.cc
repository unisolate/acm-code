#include <bits/stdc++.h>
#define MX 100010
using namespace std;
int 
bool v[MX];
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
    	memset(v,false,sizeof(v));
    	int p=0;
        while (m--)
        {
            scanf("%c%d", &f, &d);
            v[d]=true;
            if (f == '+')
            {
            	++p;
            	if()
            }
            else
            {
            	--p;
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
        	if(v[i])
        		++ans;
        }
        printf("%d\n",ans);
        if(ans)
        {
        	for(int i=1;i<=n;++i)
        	{
        		if()
        		{
        			printf("%d%c",i);
        		}
        	}
        }
    }
    return 0;
}