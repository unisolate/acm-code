#include <stdio.h>
int main()
{
    int n;
    long num,ten=1;
    scanf ("%ld",&num);
    for (n=1;n<=9;n++)
    {
        ten *= 10;
        if ((num % ten) == num)
        {
            printf ("%d",n);
            break;
        }

    }


    return 0;
}
