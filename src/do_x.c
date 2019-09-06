/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:03:37 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 14:03:39 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_leading_zero(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	get_num(t_all *all)
{
	uintmax_t	num;

	if (ft_strcmp(all->arg_table, "hh") == 0)
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

static t_all		*do_x(t_all *all, uintmax_t num, char *str, int align_left)
{
	int			n_b;
	int			n_w;

	if ((n_w = ft_strlen(str)) && all->format[4] == '#' && num &&
			all->format[3] == '0' && all->width_predot)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && all->format[4] == '#' && num)
	{
		all->width_predot -= 2;
		all->size += 2;
	}
	n_b = (n_w <= all->precision_afterdot && all->precision_afterdot > 0) ? all->precision_afterdot : n_w;
	all->size += (n_b <= all->width_predot) ? all->width_predot : n_b;
	if (!align_left)
		do_gap(all, ' ', all->width_predot - n_b, 0);
	print_leading_zero(num, all->format[4], all->format_table);
	do_gap(all, '0', all->precision_afterdot - n_w, 0);
	ft_putstr(str);
	if (align_left)
		do_gap(all, ' ', all->width_predot - n_b, 0);
	return (all);
}

t_all				*do_x(t_all *all)
{
	char		*str;
	char		c;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(all);
	if (num == 0 && all->precision_afterdot == 0)
	{
		do_gap(all, ' ', all->width_predot, 1);
		return (all);
	}
	c = 'a';
	if (all->format_table == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16))) //take a look at ft_itoa_base
		exit(-1);
	if (all->format[0] == '-')
		align_left = 1;
	if (all->format[3] == '0' && all->precision_afterdot == -1 && !all->format[0])
		all->precision_afterdot = all->width_predot;
	do_x(all, num, str, align_left);
	free(str);
	return (all);
}
