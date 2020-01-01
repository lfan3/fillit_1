#include <stdio.h>
#include <stdarg.h>
#include '../include/libft.h'

int ft_printf(char *format, ...)
{
    //parsing function to format- return a list chaine with the format
    //get the write format and give each argument to a funcion pointeurs
    unsigned int i = 0;
    va_list ap;
    va_start(ap, format);
    while(*(format + i))
    {   
        if (*(format + i) == '%' && *(format + i + 1) != '%')
            i++;
        else
            return -1;
        //entier
        if (*(format + i) == 'd')

        printf("%c\n", va_arg(ap, int));
        i++;
    }
    va_end(ap);
}

int main()
{
    int a = 12;
    printf("im %d entier\n", a);
//    printf("im %%d entier\n", a, a);
  
}
