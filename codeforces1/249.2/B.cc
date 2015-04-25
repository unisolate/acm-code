#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char a[100];
    int k;
    scanf("%s%d", a, &k);
    int temp, pos = 0, len = strlen(a);
    while (k--)
    {
        pos = 0;
        while (a[pos] >= a[pos + 1])
        {
            pos++;
            if (pos + 1 == len)
                break;
        }
        if (pos + 1 == len)
            break;
        if (a[pos] < a[pos + 1])
        {
            temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;
        }
    }
    printf("%s\n", a);
    return 0;
}