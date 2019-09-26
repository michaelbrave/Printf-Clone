/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:00:52 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 04:03:06 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_master(t_all *all, char *str)
{
	all->altdone = 0;
	all->signdone = 0;
	if (all->precision == 0 && ZERO && PRE1 && all->str != NULL)
		str[0] = '\0';
	if ((all->precision != 0 && *str != '\0') || all->zeroprecision == '0')
		str = format_precision(all, str);
	if (all->spec == 'p')
		str = format_p(all, str);
	if (all->width != 0)
		str = format_width(all, str);
	if (all->alt == '#' && all->altdone == 0)
		str = format_alt(all, str);
	if (NUMBER)
	{
		if (SIGN && (all->signdone == 0))
			str = format_sign(all, str);
	}
	return (str);
}

char	*format_alt(t_all *all, char *str)
{
	char *tmp;

	tmp = NULL;
	all->altdone = 1;
	if (str[0] == '0' && str[1] == '\0')
		return (str);
	else if ((all->spec == 'x' || all->spec == 'X') && str[0] != '\0')
		tmp = ft_strjoin("0x", str);
	else if (all->spec == 'o')
	{
		if (all->width == 0 && all->zeroprecision == '0')
			tmp = ft_strjoin("0", str);
		else if (all->precision == 0)
			tmp = ft_strjoin("0", str);
		else
			return (str);
	}
	else if (all->spec == 'f')
		tmp = ft_strjoin(str, ".");
	else
		return (str);
	free(str);
	str = tmp;
	return (str);
}

char	*format_sign(t_all *all, char *str)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strnew(2);
	tmp[0] = 0;
	tmp[1] = '\0';
	all->signdone = 1;
	if (all->neg == 1)
		tmp[0] = '-';
	else if (all->sign == '+' && ft_atoi(str) >= 0)
		tmp[0] = '+';
	else if (all->sign == ' ' && ft_atoi(str) >= 0)
		tmp[0] = ' ';
	ret = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (ret);
}
