/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:01 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:09:03 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// converts to int/decimal

int     do_d(t_all *all)
{
	char *str = NULL;
	char *tmp;

	str = NULL;
	str = length(all, str, 10);
	str = format_master(all, str);
	tmp = all->toprint;
	all->toprint = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	all->size = ft_strlen(all->toprint);
	return(0);
}