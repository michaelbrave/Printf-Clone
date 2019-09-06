/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:03:22 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 14:03:24 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_all *all)
{
	uintmax_t	num;

	if (all->format_table == 'U')
		num = (unsigned long)(va_arg(all->args, unsigned long int));
	else if (ft_strcmp(all->arg_table, "hh") == 0)
		num = (unsigned char)(va_arg(all->args, unsigned int));
	else if (ft_strcmp(all->arg_table, "h") == 0)
		num = (unsigned short)(va_arg(all->args, unsigned int));
	else if (ft_strcmp(all->arg_table, "ll") == 0)
		num = (unsigned long long)(va_arg(all->args, unsigned long long int));
	else if (ft_strcmp(all->arg_table, "l") == 0)
		num = (unsigned long)(va_arg(all->args, unsigned long int));
	else if (ft_strcmp(all->arg_table, "j") == 0)
		num = (uintmax_t)(va_arg(all->args, uintmax_t));
	else if (ft_strcmp(all->arg_table, "z") == 0)
		num = (size_t)(va_arg(all->args, size_t));
	else
		num = (unsigned int)(va_arg(all->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static int			get_tens(uintmax_t num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_all		*do_u2(t_all *all, uintmax_t num, int num_width, int left)
{
	int			not_blank;

	not_blank = num_width;
	if (num_width <= all->precision_afterdot)
		not_blank = all->precision_afterdot;
	all->size += (not_blank <= all->width_predot) ? all->width_predot : not_blank;
	if (!left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	do_gap(all, '0', all->precision_afterdot - num_width, 0);
	ft_putnbrumax_fd(num, 1);
	if (left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	return (all);
}

t_all				*do_u(t_all *all)
{
	uintmax_t	num;
	int			num_width;
	int			left;

	left = 0;
	num = get_num(all);
	if (num == 0 && all->precision_afterdot == 0)
	{
		do_gap(all, ' ', all->width_predot, 1);
		return (all);
	}
	num_width = get_tens(num);
	if (all->format[0] == '-')
		left = 1;
	if (all->format[3] == '0' && all->precision_afterdot == -1 && !all->format[0])
		all->precision_afterdot = all->width_predot;
	do_u(all, num, num_width, left);
	return (all);
}