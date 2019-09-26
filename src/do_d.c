/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:01 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 18:17:37 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_d(t_all *all)
{
	char *str;
	char *tmp;

	str = NULL;
	str = length(all, str, 10);
	str = format_master(all, str);
	all->size = all->size + ft_strlen(str);
	tmp = all->toprint;
	all->toprint = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (0);
}
