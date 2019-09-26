/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:08:31 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 03:45:29 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_c(t_all *all)
{
	char	*str;
	char	*tmp;

	str = NULL;
	all->length[2] = 'h';
	str = length(all, str, 10);
	str = format_master(all, str);
	all->size = all->size + ft_strlen(str);
	tmp = all->toprint;
	if (*str == '\0')
		all->toprint = ft_strjoin_len(tmp, str, all->size);
	else
		all->toprint = ft_strjoin(tmp, str);
	return (0);
}
