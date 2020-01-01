#include "../include/ft_printf.h"
#include <unistd.h>
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (n--)
		*str++ = (unsigned char)c;
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

