#include "../include/ft_printf.h"
#include <stdlib.h>
static char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
		ft_memset(str, 0, size + 1);
	return (str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = -1;
	if (!src)
	{
		return (0);
	}
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

static size_t	ft_countdigit(int n)
{
	size_t	count;

	count = 0;
	while (n /= 10)
		count++;
	return (count + 1);
}

char			*ft_itoa(int n)
{
	int			is_neg;
	char		*str;
	size_t		size;

	is_neg = 0;
	size = ft_countdigit(n);
	if (!(str = ft_strnew(size + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
		size++;
	}
	str += size;
	while (size--)
	{
		*--str = (char)(n % 10 + '0');
		n /= 10;
		if (is_neg && size == 0)
			*str = '-';
	}
	return (str);
}
