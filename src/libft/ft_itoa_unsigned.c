#include "libft.h"

char		*ft_itoa_unsigned(unsigned int n, int base)
{
	int		        arraycount;
	unsigned int	tmp;
	char	        *str;

	tmp = n;
	arraycount = ft_numplace(tmp, base);
	if (!(str = (char *)ft_strnew(arraycount)))
		return (NULL);
	while (arraycount--)
	{
		str[arraycount] = (tmp % base) + '0';
		tmp = tmp / base;
	}
	return (str);
}