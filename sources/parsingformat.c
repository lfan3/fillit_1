
#include <stdlib.h>
#include "../include/ft_printf.h"
// need to put in the noeud
void parsingformat(char *format, t_format **head, unsigned int i, unsigned int preci)
{
    char *f_controler;

    t_format *new_node = malloc(sizeof(t_format));
    // get flags, with, precision, length, cs
    f_controler = cp_format_contro_str(format, i);
    new_node->flags = get_flags_tab(f_controler, i);
    new_node->width = get_width(format, i);
    new_node->precision = preci;
    new_node->len = get_output_length(f_controler);
    new_node->c_s = format[i];
 //   printf("flags %s width %d precision %d len %d cs %c\n",\
            new_node->flags, new_node->width, new_node->precision, new_node->len, new_node->c_s);

}





