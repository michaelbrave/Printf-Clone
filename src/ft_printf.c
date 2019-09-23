/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:22 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:10:23 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	t_all *all;
	all = initialize((char *)format);

	if (format)
	{
		va_start(all->args, format);
		print_or_parse(all);
		va_end(all->args);
	}
	else
		return(0);
	cleanclean(all);
	//free(all);
	return (all->size);
}
