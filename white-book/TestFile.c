#include <stdio.h>

int main()
{
      int a, c, d, i, j, k;
      scanf("%d", &a);
      while (a--)
      {
          scanf("%d%d", &c, &d);
          for (i = 0; i < d; i++)
          {
              for (k = 1; k <= c; k++)
              {
                  for (j = 0; j < k; j++)
                      printf("%d", k);
                  printf("\n");
              }
              for (k = c-1; k >= 1; k--)
              {
                  for (j = 0; j < k; j++)
                      printf("%d", k);
                  printf("\n");
              }
              if (a != 0 || i != d - 1)
                 printf("\n");
          }
      }
    return 0;
}
