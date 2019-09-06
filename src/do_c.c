/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:01:02 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 14:01:04 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//this is what handles characters

t_all 	*do_c(t_all *all)
{
    wint_t c;

	if (ft_strcmp(all->arg_table, "l") == 0)
		c = (unsigned long)va_arg(all->args, unsigned long);
	else if (all->flag == 'C')
		c = va_arg(all->args, wint_t);
	else
		c = (char)va_arg(all->args, int);
	//c = (wint_t)c;
	if (all->format[3] == '0' && all->format[0] != '-')
		do_gap(all, '0', all->width_predot - 1, 1);
	else if (all->format[0] != '-')
		do_gap(all, ' ', all->width_predot - 1, 1);
	do_wchar(c, all);
	if (all->format[0] == '-')
		do_gap(all, ' ', all->width_predot - 1, 1);
	return (all);
}