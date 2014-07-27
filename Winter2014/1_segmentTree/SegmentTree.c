#include <stdio.h>

int ql,qr;
int query(int o,int L,int R)
{
	int M=L+(R-L)/2,ans=INF;
	if(ql<=L&&R<=qr) return minv[o];
	if(ql<=M) ans=min(ans,query(o*2,L,M));
	if(M<qr) ans=min(ans,query(o*2+1,M+1,R));
	return ans;
}

int p,v;
void update(int o,int L,int R)
{
	int M=L+(R-L)/2;
	if(L==R) minv[o]=v;
	else{
		if(p<=M) update(o*2,L,M);else update(o*2,M+1,R);
		minv[o]=min(minv[o*2],minv[o*2+1]);
	}
}