/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:41 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 02:43:53 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_p(t_all *all, char *str)
{
	char *tmp;

	if (all->zeroprecision == '0' && str[0] == '0' && str[1] == '\0')
		str = ft_strdup("0x");
	else
	{
		tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
	}
	return (str);
}

int		do_p(t_all *all)
{
	char *str;
	char *tmp;

	str = NULL;
	all->length[6] = 'u';
	all->length[3] = 'l';
	str = length(all, str, 16);
	str = format_master(all, str);
	all->size = all->size + ft_strlen(str);
	tmp = all->toprint;
	all->toprint = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (0);
}
