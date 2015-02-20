/* Programmming Exercise 7-9 */
#include <stdio.h>
#define NO 0
#define YES 1
int main(void)
{
   unsigned long long num;                      /* value to be checked */
   unsigned long long div;                      /* potential divisors  */
   unsigned long long lim;                      /* limit to values     */
   unsigned long long fin;
   int prime=NO;

   printf("Please enter limit to values to be checked; ");
   printf("Enter q to quit.\n");
   while (scanf("%llu", &lim) == 1 && lim > 0)
   {
        for (num = lim ; num>0,prime==NO; num--)
        {
            for (div = 2, prime = YES; (div * div) <= num; div++)
                if (num % div == 0)
                    prime = NO;           /* number is not prime  */
            if (prime == YES)
                printf("%llu is prime.\n", num);
      }
      prime = NO;

      printf("Please enter another limit; ");
      printf("Enter q to quit.\n");
   }
   return 0;
}
