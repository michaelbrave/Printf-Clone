/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:05 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 03:02:09 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_capitolize(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] >= 'a' && tmp[i] <= 'z')
			tmp[i] = tmp[i] - 32;
		i++;
	}
	return (tmp);
}

int		do_x(t_all *all)
{
	char	*str;
	char	*tmp;

	str = NULL;
	all->length[6] = 'u';
	str = length(all, str, 16);
	str = format_master(all, str);
	all->size = all->size + ft_strlen(str);
	if (all->spec == 'X')
		str = x_capitolize(str);
	tmp = ft_strjoin(all->toprint, str);
	free(str);
	free(all->toprint);
	all->toprint = tmp;
	return (0);
}
