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

char	*ft_strstr(const char *str, const char *to_find)
{
	int	search_i;
	int	find_i;

	if (!*to_find)
		return ((char *)str);
	search_i = 0;
	while (str[search_i])
	{
		if (str[search_i] == *to_find)
		{
			find_i = 0;
			while ((str[search_i + find_i] == to_find[find_i])
					&& str[search_i + find_i])
				find_i++;
			if (!to_find[find_i])
				return ((char *)(str + search_i));
		}
		search_i++;
	}
	return (0);
}
