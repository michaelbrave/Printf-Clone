/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:01:25 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/01 14:01:30 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// do_percent

static t_all	*do_percent(t_all *all)
{
	if (all->format[3] == '0' && all->precision_afterdot <= 0 && !all->format[0])
	{
		all->precision_afterdot = all->width_predot;
		all->width_predot = 0;
	}
	if (all->format[0] != '-')
		do_gap(all, ' ', all->width_predot - 1, 1);
	if (all->format[3] == '0')
		do_gap(all, '0', all->precision_afterdot - 1, 1);
	write(1, "%", 1);
	if (all->format[0] == '-')
		do_gap(all, ' ', all->width_predot - 1, 1);
	all->size++;
	return (all);
}

// do_other

t_all			*do_other(t_all *all)
{
	if (all->copy2[all->i] == '%')
	{
		do_percent(all);
		return (all);
	}
	if (all->format[3] == '0' && all->precision_afterdot <= 0 && !all->format[0])
	{
		all->precision_afterdot = all->width_predot;
		all->width_predot = 0;
	}
	if (all->format[0] != '-')
		do_gap(all, ' ', all->width_predot - 1, 1);
	if (all->format[3] == '0')
		do_gap(all, '0', all->precision_afterdot - 1, 1);
	write(1, &all->copy[all->i], 1);
	if (all->format[0] == '-')
		do_gap(all, ' ', all->width_predot - 1, 1);
	all->size++;
	return (all);
}


// do_gap

void	do_gap(t_all *all, char c, int size, int update_size)
{
	char	*str;

	if (size > 0)
	{
		if (update_size)
			all->size += size;
		if (!(str = ft_strnew(size)))
			exit(-1);
		ft_memset(str, c, size);
		write(1, str, size);
		free(str);
	}
}

// do_wchar and supporting files
static void		oct_4(wint_t c) //find another way to do these
{
	unsigned char put[4];

	put[0] = (c >> 18) + 240;
	put[1] = ((c >> 12) & 63) + 128;
	put[2] = ((c >> 6) & 63) + 128;
	put[3] = ((c & 63) + 128);
	write(1, put, 4);
}

static void		oct_3(wint_t c) //find another way to do these
{
	unsigned char put[3];

	put[0] = (c >> 12) + 224;
	put[1] = ((c >> 6) & 63) + 128;
	put[2] = ((c & 63) + 128);
	write(1, put, 3);
}

static void		oct_2(wint_t c) //find another way to do these
{
	unsigned char put[2];

	put[0] = (c >> 6) + 192;
	put[1] = ((c & 63) + 128);
	write(1, put, 2);
}

static void		oct_1(wint_t c) //find another way to do these
{
	write(1, &c, 1);
}

void	do_wchar(wint_t c, t_all *all)
{
	if (c <= 127)
	{
		all->size += 1;
		oct_1(c);
	}
	if (c >= 127 && c <= 2047)
	{
		all->size += 2;
		oct_2(c);
	}
	if (c >= 2048 && c <= 65535)
	{
		all->size += 3;
		oct_3(c);
	}
	if (c >= 65536 && c <= 2097151)
	{
		all->size += 4;
		oct_4(c);
	}
}
