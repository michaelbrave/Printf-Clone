/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:01:28 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 20:19:08 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_negative(t_all *all, char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
	{
		while (str[++i])
			str[i] = str[i + 1];
		str[i] = '\0';
		all->neg = 1;
	}
	return (str);
}

char	*length(t_all *all, char *str, int base)
{
	if (all->length[1] == 'h')
		str = make_short(all, str, base);
	else if (all->length[2] == 'h')
		str = make_char(all, str, base);
	else if (all->length[3] == 'l')
		str = make_long(all, str, base);
	else if (all->length[4] == 'l')
		str = make_long_long(all, str, base);
	else
		str = make_int(all, str, base);
	if (all->neg == 1)
		check_negative(all, str);
	return (str);
}
