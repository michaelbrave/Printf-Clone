/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:00:28 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/25 17:24:45 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_percent(t_all *all)
{
	char *str;
	char *tmp;

	str = ft_strnew(2);
	str[0] = '%';
	str[1] = '\0';
	str = format_master(all, str);
	all->size = all->size + ft_strlen(str);
	tmp = all->toprint;
	all->toprint = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (0);
}
