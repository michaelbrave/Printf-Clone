/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:01:13 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 14:01:15 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void			print_leading_zero(uintmax_t num, char hash)
{
	if (hash == '#' && num)
		write(1, "0", 1);
}

static uintmax_t	get_num(t_all *all)
{
	uintmax_t	num;

	if (all->format_table == 'O')
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

static t_all		*print_u(t_all *all, uintmax_t num, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (all->format[4] == '#' && num)
		num_width++;
	not_blank = num_width;
	if (num_width <= all->precision_afterdot && all->precision_afterdot > 0)
		not_blank = all->precision_afterdot;
	all->size += (not_blank <= all->width_predot) ? all->width_predot : not_blank;
	if (!left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	print_leading_zero(num, all->format[4]);
	do_gap(all, '0', all->precision_afterdot - num_width, 0);
	ft_putstr(str);
	free(str);
	if (left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	return (all);
}

t_all				*do_o(t_all *all)
{
	char		*str;
	uintmax_t	num;
	int			left;

	left = 0;
	num = get_num(all);
	if (num == 0 && all->precision_afterdot == 0 && all->format[4] != '#')
	{
		do_gap(all, ' ', all->width_predot, 1);
		return (all);
	}
	if (!(str = ft_itoa_base(num, 8)))
		exit(-1);
	if (all->format[0] == '-')
		left = 1;
	if (all->format[3] == '0' && all->precision_afterdot == -1 && !all->format[0])
		all->precision_afterdot = all->width_predot;
	print_u(all, num, str, left);
	return (all);
}
