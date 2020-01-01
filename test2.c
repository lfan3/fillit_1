#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void ma_printf(char *p, ...)
{
    unsigned int i = 0;
  //  unsigned int j = 0;
    va_list ap;
    va_start(ap, p);
    char v[30];
    int n;

    while (*(p + i))
    {
        if(*(p + 0) == '%') // from the first position, the real printf peurhaps not
            i++;
        if(*(p+1) == 'c')
        {
            fputc(va_arg(ap, int), stdout);       
        }
        if(*(p + 1)== 'd')
        {
            n = va_arg(ap, int);
            itoa(n, v, 10);
        }
        for(int j=0;j<strlen(v);j++){
         fputc(v[j],stdout);
        }


    }
    va_end(ap);
}
int main()
{
    char c = 'A';
    ma_printf("%c", c);
    return 0;
}