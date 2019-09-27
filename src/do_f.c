/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:14:40 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 03:47:55 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_long_double(t_all *all, char *str, long double holder)
{
	long long		predot;
	long double		afterdot;
	char			*beforedot;
	char			*beyonddot;

	holder = (va_arg(all->args, long double));
	predot = (long long)holder;
	afterdot = holder - predot;
	beyonddot = ft_itoa_float(all, afterdot);
	beyonddot = format_precision(all, beyonddot);
	beyonddot = ft_strjoin(".", beyonddot);
	beforedot = ft_itoa_base(predot, 10);
	beforedot = format_width(all, beforedot);
	str = ft_strjoin(beforedot, beyonddot);
	free(beforedot);
	free(beyonddot);
	str = roundup(str);
	return (str);
}

char	*ft_itoa_float(t_all *all, double n)
{
	int			arraycount;
	char		*str;
	char		*str2;
	int			i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (all->precision != 0)
		arraycount = all->precision;
	else
	{
		arraycount = 6;
		all->precision = 6;
		all->padfill = '0';
	}
	while (i < arraycount)
	{
		n = (n * 10);
		i++;
	}
	str = ft_itoa_base((intmax_t)n, 10);
	str2 = ft_strnew(ft_strlen(str) + 1);
	str2 = ft_strdup(str);
	return (str);
}

char	*roundup(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (str[i] >= '5' && str[i] <= '9')
	{
		while (i && (str[i] == '9' || str[i] == '.'))
		{
			(str[i] != '.') ? str[i] = '0' : 0;
			i--;
		}
		str[i] += 1;
	}
	return (str);
}

char	*float_length(t_all *all, char *str, long double holder)
{
	long			predot;
	double			afterdot;
	char			*beforedot;
	char			*beyonddot;
	char			*tmp;

	tmp = NULL;
	if (all->length[5] == 'L')
		str = make_long_double(all, str, holder);
	else
	{
		holder = (va_arg(all->args, double));
		predot = (long)holder;
		afterdot = holder - predot;
		beyonddot = ft_itoa_float(all, afterdot);
		beyonddot = format_precision(all, beyonddot);
		beyonddot = ft_strjoin(".", beyonddot);
		beforedot = ft_itoa_base(predot, 10);
		beforedot = format_width(all, beforedot);
		str = ft_strjoin(beforedot, beyonddot);
		str = roundup(str);
	}
	return (str);
}

int		do_f(t_all *all)
{
	char			*str;
	char			*tmp;
	double long		holder;

	holder = 0;
	str = NULL;
	str = float_length(all, str, holder);
	all->size = all->size + ft_strlen(str);
	tmp = all->toprint;
	all->toprint = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (0);
}
