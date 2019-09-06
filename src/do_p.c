/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:03:14 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 14:03:16 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static uintmax_t	get_num(t_all *all)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(all->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_all		*print_u(t_all *all, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	all->size += (not_blank <= all->width_predot) ? all->width_predot : not_blank;
	if (!align_left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	write(1, "0x", 2);
	do_gap(all, '0', (all->precision_afterdot - num_width) + 2, 1);
	ft_putstr(str);
	if (align_left)
		do_gap(all, ' ', all->width_predot - not_blank, 0);
	free(str);
	return (all);
}

t_all				*do_p(t_all *all)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(all);
	if (!(str = ft_itoa_base(num, 16)))
		exit(-1);
	if (all->format[0] == '-')
		align_left = 1;
	if (all->precision_afterdot == 0 && num == 0)
		*str = '\0';
	if (all->format[3] == '0' && all->precision_afterdot == -1 && !all->format[0])
	{
		all->precision_afterdot = all->width_predot - 2;
		all->width_predot = 0;
	}
	print_u(all, str, align_left);
	return (all);
}