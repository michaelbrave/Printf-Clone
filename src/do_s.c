/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <mbrave@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:50 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/26 01:14:14 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_s(t_all *all)
{
	char *str;
	char *tmp;

	str = ft_strdup(va_arg(all->args, char *));
	if (str == NULL)
		str = ft_strdup("(null)");
	if (*str == '\0')
		all->precision = '\0';
	str = format_master(all, str);
	all->size = all->size + ft_strlen(str);
	tmp = all->toprint;
	all->toprint = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (0);
}
