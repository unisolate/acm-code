#include <cstdio>
#define H n*2
#define I n*2+1
#define J l,m,n*2
#define K m+1,r,n*2+1
#define M int m=l+r>>1
#define P if(s[n]==-1&&s[H]==s[I])s[n]=s[H]
#define D if(s[n]!=-1)s[H]=s[I]=s[n],s[n]=-1
int t,N,m,L,R,v,s[2<<21];char o[9];void B(int l=1,int r=N,int n=1){s[n]=-1;if(l==r){scanf("%d",s+n);return;}M;B(J);B(K);P;}void U(int l=1,int r=N,int n=1){if(R<=l&&r<=v&&s[n]!=-1){if(o[0]==65)s[n]&=L;else if(o[0]==79)s[n]|=L;else s[n]^=L;return;}D;M;if(R<=m)U(J);if(m<v)U(K);P;}int Q(int l=1,int r=N,int n=1){if(L<=l&&r<=R&&s[n]!=-1)return s[n]*(r-l+1);D;M;int a=0;if(L<=m)a+=Q(J);if(m<R)a+=Q(K);return a;}int main(){scanf("%d",&t);while(t--){scanf("%d%d",&N,&m);B();while(m--){scanf("%s%d%d",o,&L,&R);if(o[0]==83){++L,++R;printf("%d\n",Q());}else{scanf("%d",&v);++v,++R;U();}}}}