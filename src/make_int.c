/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:14:50 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 23:46:53 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_int_unsigned(t_all *all, char *str, int base)
{
	unsigned int	u;

	u = ((unsigned int)va_arg(all->args, unsigned int));
	if (all->length[2] == 'h')
	{
		if (u == UCHAR_MAX)
			u = (wchar_t)u;
		else
			u = (char)u;
	}
	free(str);
	str = ft_itoa_unsigned(u, base);
	return (str);
}

char	*make_int_signed(t_all *all, char *str)
{
	int	i;

	i = ((int)va_arg(all->args, int));
	if (all->length[2] == 'h')
		i = (char)i;
	if ((int)i < 0)
		all->neg = 1;
	free(str);
	str = ft_itoa_base((wint_t)i, 10);
	return (str);
}

char	*make_int(t_all *all, char *str, int base)
{
	if (all->length[6] != 'u')
		str = make_int_signed(all, str);
	else if (all->length[6] == 'u')
		str = make_int_unsigned(all, str, base);
	return (str);
}
