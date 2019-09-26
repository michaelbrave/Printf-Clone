/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:16:06 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 20:35:57 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_short_signed(t_all *all, char *str, int base)
{
	short	h;

	h = ((short)va_arg(all->args, int));
	if ((short)h < 0)
		all->neg = 1;
	str = ft_itoa_base(h, base);
	return (str);
}

char	*make_short_unsigned(t_all *all, char *str, int base)
{
	unsigned short h;

	if (all->length[6] == 'u')
		h = ((unsigned short)va_arg(all->args, int));
	else
		h = ((short)va_arg(all->args, int));
	str = ft_itoa_base(h, base);
	return (str);
}

char	*make_short(t_all *all, char *str, int base)
{
	if (all->length[6] != 'u')
		str = make_short_signed(all, str, base);
	else if (all->length[6] == 'u')
		str = make_short_unsigned(all, str, base);
	return (str);
}
