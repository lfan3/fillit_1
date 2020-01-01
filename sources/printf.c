#include <stdio.h>
#include <stdarg.h>
#include "../include/ft_printf.h"
#include "../include/libft/libft.h"
int ft_printf(char *format, ...)
{
    //parsing function to format- return a list chaine with the format
    //get the write format and give each argument to a funcion pointeurs
    t_format *head = NULL;
    unsigned int i;
    va_list ap;
    va_start(ap, format);

    while(*format)
    {
        if (*format == '%' && *(format + 1) == '%')
        {
            ft_putchar('%');
            format++;
        }
        if(*format == '%' && *(format + 1) != '%')
        {
            i = get_format_valid_lenth(format);
            int preci = get_presition(format, i);
     
            if (preci == -1)
            {
                preci = va_arg(ap, int);
                parsingformat(format, &head, i, preci);
            }
            else
                parsingformat(format, &head, i, preci);
        }
        format++;
    }
    va_end(ap);
    return 0;
}

int main()
{
    int a = 12;
    ft_printf("%03.4+d0 %5d", 12, 15 );
    ft_printf("%.*", 5, 15 );
 //   ft_printf("%%%%");
  //  printf("% d0  da", 2);
  //  printf("\n");
  //  printf("im %%%%d  \n");
  // 
  //  printf("im %--5d entier\n", -12);
  //  printf("im %--5d entier\n", 12);
  //  printf("im %ld entier\n", 120120514654564565);
  //  printf("im %ld entier\n", 116543465456456151);
  //  printf("im %++00d entier\n", 12);
  //  printf("im %#X entier\n", 12);
    
  
}
