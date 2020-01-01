#include "../include/ft_printf.h"

int checkformat(char *format)
{
    //verifier for the %d the wrong format
    int percounter;
    while (*format)
    {
        if (*format == '%' && *(format + 1) == '%')
        {
            percounter = 2;
            format++;
        }
        format++;
    }
    if (percounter == 2)
        return -1;
    return 0;
}