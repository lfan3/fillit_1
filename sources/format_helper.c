#include <stdlib.h>
#include "../include/ft_printf.h"

// after the format is been check, now we put every useful infomation in a list chaine
int     get_format_valid_lenth(char *format)
{
    unsigned int i = 0;
   while (format[i])
    {
        if (format[i] == ' ' && format[i + 1] == '%')
            break;
        if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' || \
            format[i] == 'd' || format[i] == 'i' || format[i] == 'o' || \
            format[i] == 'u' || format[i] == 'x' || format[i] == 'X' || \
            format[i] == 'f' )
            break;
        i++;            
    } 
    return i; 
}

char    *cp_format_contro_str(char *format, int i)
{
    char *f_controler ;
    int j = 0;

    if(!(f_controler= (char *)malloc(sizeof(char)*(i+1))))
        return NULL;
    while(j < i)
    {
        f_controler[j] = format[j];
        j++;
    }
    return f_controler;
}

char    *get_flags_tab(char *valid_format, unsigned i)
{
    int j = 0;
    char *flags;
    int k = 0;

    if (!(flags = malloc(sizeof(char) *(i + 1))))
        return NULL;
    ft_bzero(flags, (i+1));
    while (valid_format[j])
    {
        if ((valid_format[j] == ' ' || valid_format[j] == '#' || valid_format[j] == '+' ||\
            valid_format[j] == '-' || valid_format[j] == '0'))
            {
                flags[k] = valid_format[j];
                k++;
            }
        j++;     
    }
 
/*******????.?. so wired !!! the printf is working for while not single one !!!!!*/
//       printf("flags %c\n", flags[0]);
//       printf("flags %c\n", flags[1]);
//
//    while(flags[m])
//    {
//       printf("flags %c\n", flags[m]);
//       printf("m %d\n", m);
//       m++;
//    }*/
//
    return flags;
}

int     get_width(char *format, unsigned int i)
{
    unsigned int j = 0;
    unsigned int res = 0;
    
    while(j < i)
    {
        if (format[j]> '0' && format[j] <= '9' && format[j] != '.')
            res = (res * 10) + format[j] - '0';
        if (format[j] == '.')
            break;
        j++;
    }
    return res;
}
//if the precision is beginin with *, then res = -1; 
//otherwise we get directly precision
int     get_presition(char *format, unsigned int i)
{
    unsigned int j = 0;
    unsigned int res = 0;
    int precision = 0;
    

    while(j < i)
    {
        if (format[j] == '.' && (format[j+1]> '0' && format[j+1] <= '9'))
        {
            precision = 1;
            j++;
            while (precision == 1 && j < i)
            {
                if (format[j]> '0' && format[j] <= '9')
                    res = (res * 10) + format[j] - '0';
                j++;
            }
        }
        // need to see the next argument
        if (format[j] == '.' && (format[j+1] == '*'))
        {
            res = -1;
            return res;
        }
        j++;
    }
    
    return res;
}
//get lenth
//hh,h,l,ll,j,z
int     get_output_length(char *valid_format)
{
    if(ft_strstr(valid_format, "hh"))
        return 1;
    else if (ft_strstr(valid_format, "h"))
        return 2;
    else if (ft_strstr(valid_format, "l"))
        return 8;
    else if (ft_strstr(valid_format, "ll"))
        return 8;
    //else if (ft_strstr(valid_format, "j"))
    //else if (ft_strstr(valid_format, "z"))
    else
        return 0;
}
