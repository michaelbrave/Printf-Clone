/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:09:42 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 19:47:24 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_spec(t_all *all, int i)
{
	while (all->spec == 0 && SPEC(i) != '\0')
	{
		if (SPEC(i) == '%')
			all->spec = SPEC(i);
		else if (SPEC(i) == 's')
			all->spec = SPEC(i);
		else if (SPEC(i) == 'c')
			all->spec = SPEC(i);
		else if (SPEC(i) == 'd' || SPEC(i) == 'i')
			all->spec = SPEC(i);
		else if (SPEC(i) == 'u')
			all->spec = SPEC(i);
		else if (SPEC(i) == 'o')
			all->spec = SPEC(i);
		else if (SPEC(i) == 'x' || SPEC(i) == 'X')
			all->spec = SPEC(i);
		else if (SPEC(i) == 'p')
			all->spec = SPEC(i);
		else if (SPEC(i) == 'f')
			all->spec = SPEC(i);
		else
			i++;
	}
	all->here_spec = all->i + i;
}

void	finder_main(t_all *all)
{
	all->i++;
	length_reset(all);
	while (all->i < all->here_spec)
	{
		if (LFLAG)
			find_length(all);
		if (all->str[all->i] == '0')
			all->padfill = '0';
		if (all->str[all->i] <= '9' && all->str[all->i] >= '1')
			find_width(all);
		if (all->str[all->i] == '.')
			find_precision(all, 0);
		if (all->str[all->i] == '#')
			all->alt = '#';
		if (all->str[all->i] == '-')
			all->align = '-';
		if (all->str[all->i] == ' ' && all->sign != '0' && all->sign != '+')
			all->sign = ' ';
		if (all->str[all->i] == '+' && all->sign != '0')
			all->sign = '+';
		all->i++;
	}
}

void	find_width(t_all *all)
{
	long	num;
	int		j;

	num = 0;
	j = 0;
	all->width = 0;
	while (all->i + j < all->here_spec && 1 == ft_isdigit(SPEC(j)))
	{
		if (ft_isdigit(SPEC(j)) == 1 && ft_isdigit(SPEC(j + 1)) == 0)
		{
			num = (SPEC(j) - '0');
			all->i++;
			all->width = num;
			return ;
		}
		else if (ft_isdigit(SPEC(j)) == 1 && ft_isdigit(SPEC(j + 1)) == 1)
		{
			num = (SPEC(j) - '0') * 10;
			num += SPEC(j + 1) - '0';
			all->i = all->i + 1;
		}
		j++;
	}
	all->width = num;
}

void	find_precision(t_all *all, int j)
{
	long	num;

	num = 0;
	all->i++;
	all->zeroprecision = '\0';
	all->precision = 0;
	while (all->i + j < all->here_spec && 1 == ft_isdigit(SPEC(j)))
	{
		if (ft_isdigit(SPEC(j)) == 1 && ft_isdigit(SPEC(j + 1)) == 0)
		{
			num = (SPEC(j) - '0');
			all->i++;
		}
		else if (ft_isdigit(SPEC(j)) == 1 && ft_isdigit(SPEC(j + 1)) == 1)
		{
			num = (SPEC(j) - '0') * 10;
			num += SPEC(j + 1) - '0';
			all->i = all->i + 1;
		}
		j++;
	}
	if (num == 0)
		all->zeroprecision = '0';
	all->precision = num;
}

void	find_length(t_all *all)
{
	if (SPEC(0) == 'h' && SPEC(1) != 'h')
	{
		all->length[1] = 'h';
		all->i++;
	}
	else if (SPEC(0) == 'h' && SPEC(1) == 'h')
	{
		all->length[2] = 'h';
		all->i = all->i + 2;
	}
	else if (SPEC(0) == 'l' && SPEC(1) != 'l')
	{
		all->length[3] = 'l';
		all->i++;
	}
	else if (SPEC(0) == 'l' && SPEC(1) == 'l')
	{
		all->length[4] = 'l';
		all->i = all->i + 2;
	}
	else if (SPEC(0) == 'L')
	{
		all->length[5] = 'L';
		all->i++;
	}
}
