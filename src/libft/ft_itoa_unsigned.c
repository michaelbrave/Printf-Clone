#include "libft.h"

char		*ft_itoa_unsigned(unsigned long n, int base)
{
	int		        arraycount;
	unsigned long	tmp;
	char	        *str;

	tmp = n;
	if (n == 0)
        {
            str = ft_strnew(2);
            str[0] = '0';
            str[1] = '\0';
			return(str);
        }
	arraycount = ft_numplace(tmp, base);
	if (!(str = (char *)ft_strnew(arraycount)))
		return (NULL);
	str[arraycount + 1] = '\0';
	while (arraycount--)
	{
		if ((tmp % base) > 9)
			str[arraycount] = (tmp % base) + 87;
		else
			str[arraycount] = (tmp % base) + '0';
		tmp = tmp / base;
	}

	return (str);
}