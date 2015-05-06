#include <cstdio>
#define MOD 1000000007
using namespace std;

int main() {
    int t, a, b, c, n, k, kk;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d%d", &a, &b, &c, &n, &k, &kk);
        int ans=0;
        for(int i=0;i<n;++i){
        	ans+=pow(i,k)*pow( ((a*i+b)/c),kk);
        }
    }
    return 0;
}