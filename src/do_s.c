/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 05:48:20 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/06 05:48:23 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all			*do_s(t_all *all)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(all->args, char *);
	if (all->precision_afterdot > -1 && s)
		s = ft_strndup(s, all->precision_afterdot);
	else if (all->precision_afterdot == -1 && s)
		s = ft_strdup(s);
	else if (all->precision_afterdot > -1 && !s)
		s = ft_strndup("(null)", all->precision_afterdot);
	else if (all->precision_afterdot == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	all->size += len;
	if (all->format[3] == '0' && all->format[0] != '-')
		do_gap(all, '0', all->width_predot - len, 1);
	else if (all->format[0] != '-')
		do_gap(all, ' ', all->width_predot - len, 1);
	ft_putstr(s);
	if (all->format[0] == '-')
		do_gap(all, ' ', all->width_predot - len, 1);
	free(s);
	return (all);
}
