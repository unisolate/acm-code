#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int words=0;
    char c,pre='_';
    while(c=getchar())
    {
        if(c==EOF)
            break;
        while(c!='\n')
    {
        if(isalpha(c)==0 && isalpha(pre))
            words++;
        pre = c;
        c=getchar();
        if(c=='\n'&& isalpha(pre))
            words+=1;
    }
    printf("%d\n",words);
    words=0;pre='_';
    }
    return 0;
}
