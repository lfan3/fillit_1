#include <stdlib.h>
#include "../include/ft_printf.h"

// this file controle the when the c_s = %d
//no special attribute
//then flag, width..
void case_d(int argu)
{
    char *num;
    num = ft_itoa(argu);
    ft_putstr(num);
}