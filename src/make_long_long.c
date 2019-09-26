/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_long_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:01:34 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 23:46:43 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_long_long_signed(t_all *all, char *str, int base)
{
	long long			l;

	l = ((long long)va_arg(all->args, void *));
	if ((long long)l < 0)
		all->neg = 1;
	free(str);
	str = ft_itoa_unsigned(l, base);
	return (str);
}

char	*make_long_long_unsigned(t_all *all, char *str, int base)
{
	unsigned long long	u;

	u = ((unsigned long long)va_arg(all->args, unsigned long long));
	free(str);
	str = ft_itoa_unsigned(u, base);
	return (str);
}

char	*make_long_long(t_all *all, char *str, int base)
{
	if (all->length[6] != 'u')
		str = make_long_long_signed(all, str, base);
	else if (all->length[6] == 'u')
		str = make_long_long_unsigned(all, str, base);
	return (str);
}
