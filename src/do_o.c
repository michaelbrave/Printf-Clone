/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:24 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 18:17:54 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_o(t_all *all)
{
	char *str;
	char *tmp;

	str = NULL;
	all->length[6] = 'u';
	str = length(all, str, 8);
	str = format_master(all, str);
	all->size = all->size + ft_strlen(str);
	tmp = all->toprint;
	all->toprint = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (0);
}
