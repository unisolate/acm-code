#include <stdio.h>
#include <math.h>
int main()
{
    float n,sum=0;
    for (n=1;(1/2*n-1)<pow(10,-6);n++)
    {
        sum += (1/(2*n-1))*pow(-1,n+1);
        printf ("%f\n",sum);
    }

    printf ("%f",sum);
    return 0;
}
