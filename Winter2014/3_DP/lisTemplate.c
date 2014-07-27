#include<bits/stdc++.h>  
using namespace std;  
const int mx = 10005;  
  
int lis[mx];  
  
int main()  
{  
    int N, len, i, j, x;  
    while (~scanf("%d", &N))  
    {  
        len = 0;  
        for (i = 1; i <= N; ++i)  
        {  
            scanf("%d", &x);  
            j = lower_bound(lis + 1, lis + len + 1, x) - lis;  
            lis[j] = x;  
            len = max(len, j);  
        }  
        printf("%d\n", len);  
    }  
    return 0;  
}  