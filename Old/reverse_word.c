#include <stdio.h>
#include <string.h>
int main(void)
{
    int n,length;
    char word[40];
    scanf ("%s",&word);
    length = strlen(word);
    for (n=length;n>0;n--)
        printf ("%c",word[n-1]);
    return 0;
}
