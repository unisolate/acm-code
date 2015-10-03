#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int gcd(int a, int b)
{
    return (b ? gcd(b, a % b) : a);
}
int main()
{
    int n, p[111];
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        char s[10000];
        int k = 0;
        gets(s);
        while (~sscanf(s, "%d", &p[k]))
            k++;
        for (int i = 0; i < k; ++i)
            printf("%d ", p[i]);
    }
    return 0;
}