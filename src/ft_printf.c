/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:25:20 by mbrave            #+#    #+#             */
/*   Updated: 2019/05/28 14:32:47 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *fmt, ...)
{
	t_all *all;
	all = initialize(fmt);

	if (fmt)
	{
		va_start(all->args, fmt);
		all->size = parser(all);
		va_end(all->args);
	}
	free(all); //does free work even though I malloc elsewhere?
	return (all->size); //does this do anything after it's free?
	
}