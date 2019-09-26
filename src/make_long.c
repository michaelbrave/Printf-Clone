/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:18:25 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 03:53:54 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_long_signed(t_all *all, char *str, int base)
{
	long	l;

	l = ((long)va_arg(all->args, long));
	if (l == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if ((long)l < 0)
		all->neg = 1;
	str = ft_itoa_base(l, base);
	return (str);
}

char	*make_long_unsigned(t_all *all, char *str, int base)
{
	unsigned long u;

	u = ((unsigned long)va_arg(all->args, unsigned long));
	str = ft_itoa_unsigned(u, base);
	return (str);
}

char	*make_long(t_all *all, char *str, int base)
{
	if (all->length[6] != 'u')
		str = make_long_signed(all, str, base);
	else if (all->length[6] == 'u')
		str = make_long_unsigned(all, str, base);
	return (str);
}
