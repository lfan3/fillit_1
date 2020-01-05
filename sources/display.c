#include <unistd.h>
#include "../include/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	char *ptr;

	if (!s)
		return ;
	ptr = (char*)s;
	while (*ptr)
		ft_putchar(*ptr++);
}