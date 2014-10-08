#include <cstdio>
#include <stack>
using namespace std;
char a[9999], b[9999];
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        stack<char> s;
        for (int i = 0; i < n; ++i)
            scanf(" %c", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf(" %c", &b[i]);
        a[n]=b[n]='\0';
        int p = 0;
        for (int i = 0; i < n; ++i)
        {
            while (p < n && (s.empty() || s.top() != b[i]))
            {
                s.push(a[p++]);
                printf("I");
            }
            if (s.top() != b[i])
            {
                printf(" Impossible");
                break;
            }
            else
            {
                s.pop();
                printf("R");
            }
        }
        printf("\n");
    }
    return 0;
}