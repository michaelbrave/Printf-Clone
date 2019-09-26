/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:17:25 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 23:51:07 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_char_signed(t_all *all, char *str, int base)
{
	char	c;

	c = (char)va_arg(all->args, int);
	if (NUMBER)
		str = ft_itoa_base(c, base);
	else
	{
		str = ft_strnew(1);
		str[0] = (char)c;
	}
	if (c < 0)
		all->neg = 1;
	if (str[0] == '\0')
		all->size++;
	return (str);
}

char	*make_char_unsigned(t_all *all, char *str, int base)
{
	unsigned int	c;

	base = 10;
	if (all->spec == 'o')
		base = 8;
	if (all->spec == 'x' || all->spec == 'X')
		base = 16;
	c = (unsigned char)va_arg(all->args, int);
	str = ft_itoa_base((unsigned char)c, base);
	if (str[0] == '\0')
		all->size++;
	return (str);
}

char	*make_char(t_all *all, char *str, int base)
{
	if (all->length[6] != 'u')
		str = make_char_signed(all, str, base);
	else if (all->length[6] == 'u')
		str = make_char_unsigned(all, str, base);
	return (str);
}
