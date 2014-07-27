#include <stdio.h>
int main (void)
{
    float month[12],sum=0.0;
    int n;
    for (n=0;n<12;n++)
    {
        scanf ("%f",&month[n]);
        sum+=month[n];
    }
    printf ("$%.2f\n",sum/12);
    return 0;

}
