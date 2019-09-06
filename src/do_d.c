/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:16:08 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 13:16:10 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_num(t_all *all)
{
	intmax_t	num;

	if (all->format_table == 'D')
		num = (long)(va_arg(all->args, long int));
	else if (ft_strcmp(all->arg_table, "hh") == 0)
		num = (signed char)(va_arg(all->args, int));
	else if (ft_strcmp(all->arg_table, "h") == 0)
		num = (short)(va_arg(all->args, int));
	else if (ft_strcmp(all->arg_table, "ll") == 0)
		num = (long long)(va_arg(all->args, long long int));
	else if (ft_strcmp(all->arg_table, "l") == 0)
		num = (long)(va_arg(all->args, long int));
	else if (ft_strcmp(all->arg_table, "j") == 0)
		num = (intmax_t)(va_arg(all->args, intmax_t));
	else if (ft_strcmp(all->arg_table, "z") == 0)
		num = (size_t)(va_arg(all->args, size_t));
	else
		num = (int)(va_arg(all->args, int));
	num = (intmax_t)num;
	return (num);
}

static int		get_tens(intmax_t num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_negatvity_placeholder(t_all *all, int is_negative)
{
	char	*tmp;

	tmp = all->format;
	if (is_negative)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

static t_all	*do_d2(t_all *all, intmax_t num, int num_width, int align_left)
{
	int			not_blank;
	char		negatvity_placeholder;
	int			is_negative;

	is_negative = (num < 0) ? 1 : 0;
	num *= (is_negative && num != (-9223372036854775807 - 1)) ? -1 : 1;
	negatvity_placeholder = get_negatvity_placeholder(all, is_negative);
	not_blank = num_width;
	if (num_width <= all->precision_afterdot && all->precision_afterdot >= 0)
		not_blank = all->precision_afterdot;
	if (negatvity_placeholder)
		not_blank++;
	all->size += (not_blank <= all->width_predot) ? all->width_predot : not_blank;
	if (!align_left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	if (negatvity_placeholder)
		write(1, &negatvity_placeholder, 1);
	do_gap(all, '0', all->precision_afterdot - num_width, 0);
	if (num != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(num, 1);
	else if ((all->size += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (align_left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	return (all);
}

t_all			*do_d(t_all *all)
{
	intmax_t	num;
	int			num_width;
	int			align_left;

	num = get_num(all);
	if (num == 0 && all->precision_afterdot == 0)
	{
		if (all->format[1] == '+')
			do_wchar('+', all);
		if (all->format[2] == ' ')
			do_wchar(' ', all);
		do_gap(all, ' ', all->width_predot, 1);
		return (all);
	}
	num_width = get_tens(num);
	align_left = (all->format[0] == '-') ? 1 : 0;
	if (all->format[3] == '0' && all->precision_afterdot == -1 && !all->format[0])
	{
		all->precision_afterdot = all->width_predot;
		if (num < 0 || all->format[2] || all->format[1] || all->format[0])
			all->precision_afterdot--;
	}
	do_d2(all, num, num_width, align_left);
	return (all);
}