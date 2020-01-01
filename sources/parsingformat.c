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

char    *get_flags_tab(char *format, unsigned int i)
{
    int j = 0;
    char *flags;
    int k = 0;

    if (!(flags = malloc(sizeof(char) *(i + 1))))
        return NULL;
    ft_bzero(flags, (i+1));
    while (format[j])
    {
        if (format[j] == ' ' && format[j+1] == '%')
            break;
        if ((format[j] == ' ' || format[j] == '#' || format[j] == '+' ||\
            format[j] == '-' || format[j] == '0') && (j < i))
            flags[k] = format[j];
        j++;     
        k++;   
    }
    return flags;
}

int get_width(char *format, unsigned int i)
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

int get_presition(char *format, unsigned int i)
{
    unsigned int j = 0;
    unsigned int res = 0;
    int presition = 0;
    

    while(j < i)
    {
        if (format[j] == '.' && (format[j+1]> '0' && format[j+1] <= '9'))
        {
            presition = 1;
            j++;
            while (presition == 1 && j < i)
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
// need to put in the noeud
void parsingformat(char *format, t_format **head, unsigned int i, unsigned int preci)
{
    char *flags;
    unsigned int width;

    t_format *new_node = malloc(sizeof(t_format));
    flags = get_flags_tab(format, i);
    width = get_width(format, i);
    printf("width %d\n", width);
    printf("preci %d\n", preci);
    new_node->flags = flags;
    
   // push(head, new_node);   
}





