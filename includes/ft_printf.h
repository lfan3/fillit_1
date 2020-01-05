#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

typedef struct              s_format_list
{
    //a tablea of attributs
    char                    *flags;
    int                     width;
    int                     precision;
    int                     len;
    char                    c_s;
    struct s_format_list    *next;
}                           t_format;

void    parsingformat(char *format, t_format **head, unsigned int i, unsigned int preci);
int get_presition(char *format, unsigned int i);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void    push(t_format **head, t_format *new_node);
char	*ft_strstr(const char *str, const char *to_find);
//format_helper
int     get_format_valid_lenth(char *format);
char    *cp_format_contro_str(char *format, int i);
char    *get_flags_tab(char *valid_format, unsigned i);
int     get_width(char *format, unsigned int i);
int     get_presition(char *format, unsigned int i);
int     get_output_length(char *valid_format);
//int_helper
char			*ft_itoa(int n);
//display
void	ft_putchar(char c);
void	ft_putstr(char const *s);
//case_d
void case_d(int argu);


#endif