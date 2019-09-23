/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:01:28 by mbrave            #+#    #+#             */
/*   Updated: 2019/06/25 16:01:31 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(long long n, int base)
{
	int				arraycount;
	int				neg;
	char			*str;
	char			*hexmap;

	neg = 0;
	hexmap = ft_strdup("0123456789abcdef");
	if (n == 0)
        {
            str = ft_strnew(2);
            str[0] = '0';
            str[1] = '\0';
			return(str);
        }
	if (base >= 2 && base <= 16)
	{
		if (n < 0 && (n *= -1))
			neg = 1;
		arraycount = ft_numplace(n, base);
		if (!(str = (char *)ft_strnew(arraycount + neg)))
			return (NULL);
		while (arraycount--)
		{
			str[neg + arraycount] = hexmap[n % base];
			n = n / base;
		}
		if (neg == 1)
			str[0] = '-';
		free(hexmap);
		return (str);
	}
	return(NULL);
}