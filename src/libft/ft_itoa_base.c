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

char		*ft_itoa_base(int n, int base)
{
	int				arraycount;
	int				neg;
	unsigned long	tmp;
	char			*str;
	char			*hexmap;

	neg = 0;
    
	hexmap = ft_strdup("0123456789ABCDEF");
	if (base > 2 && base < 16)
	{
		if (n < 0)
		{
			tmp = n * -1;
			neg = 1;
		}
		else
			tmp = n;
		arraycount = ft_numplace(tmp, base);
		str = (char *)ft_strnew(arraycount + neg);
		if (str == NULL)
			return (NULL);
		while (arraycount--)
		{
			str[neg + arraycount] = hexmap[tmp % base];
			tmp = tmp / base;
		}
		if (neg == 1)
			str[0] = '-';
		return (str);
	}
	else
	{
		ft_putstr("Base Must Be Between 2 and 16");
		return (NULL);
	}
}