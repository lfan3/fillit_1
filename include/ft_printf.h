#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

typedef struct              s_format_list
{
    //a tablea of attributs
    char                    *flags;
    int                     width;
    int                     presition;
    int                     lenth;
    char                    *converter;
    struct s_format_list    *next;
}                           t_format;

void    parsingformat(char *format, t_format **head, unsigned int i, unsigned int preci);
int get_presition(char *format, unsigned int i);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void    push(t_format **head, t_format *new_node);
void	ft_putchar(char c);
int     get_format_valid_lenth(char *format);
#endif