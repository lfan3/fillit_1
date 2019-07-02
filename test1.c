#include <stdarg.h>
#include <stdio.h>

int somme(int a, ...)
{
    int som = 0;
  //  int i = 0;
   //int j = a;
    int c = 0;
    va_list ap;
    va_start(ap,a);
   // while (i<j)
   // {
        c = va_arg(ap, int);
        som+= c;
     //   i++;
  //  }
    va_end(ap);
    return som;
}

int main()
{
    printf("la somme est : %d \n", somme(4,2,3,4,6));
    return (0);
}