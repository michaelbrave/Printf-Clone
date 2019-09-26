/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:22 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 22:43:17 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_all	*all;
	int		ret;

	if (!(all = (t_all*)malloc(sizeof(t_all))))
		return (0);
	*all = initialize((char *)format);
	if (format)
	{
		va_start(all->args, format);
		print_or_parse(all);
		va_end(all->args);
	}
	else
		return (0);
	ret = all->retsize;
	cleanclean(all);
	return (ret);
}
