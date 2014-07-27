#include <stdio.h>
bool prime[20000000];
 
void findprime()
{
    for (int i=0; i<20000000; i++)  // 初始化
        prime[i] = true;
 
    prime[0] = false;   // 0 和 1 不是質數
    prime[1] = false;
 
    // 找下一個未被刪掉的數字
    for (int i=2; i<20000000; i++)
        if (prime[i])
            // 刪掉質數i的倍數，從兩倍開始。保留原本質數。
            for (int j=i*i; j<20000000; j+=i)
                prime[j] = false;
}

int main()
{
    int i;
    findprime();
    for(i=3;i<100;i++)
        if(prime[i]==true)
            printf("%d\n",i);
    return 0;
}