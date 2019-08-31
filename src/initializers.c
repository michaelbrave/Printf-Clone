/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:47:58 by mbrave            #+#    #+#             */
/*   Updated: 2019/08/28 12:48:01 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	*initialize(char *fmt)
{
    t_all *all;
	if (!(all = (t_all*)malloc(sizeof(t_all))))
		return (NULL);
	all->string = fmt;
    all->copy = all->string;
    all->size = 0;
    all->i = 0;
    all->flag_table = "scSCdDiuUoOxXbp%";
	all->format_table = "-+ 0#";
	all->arg_table = "lhjz";
	return(all);
}

t_all *reinitialize(t_all *all)
{
	all->flag = '\0';
	all->format[0] = '\0';
	all->format[1] = '\0';
	all->format[2] = '\0';
	all->format[3] = '\0';
	all->format[4] = '\0';
	all->format[5] = '\0';
	all->arg[0] = '\0';
	all->arg[1] = '\0';
	all->precision_afterdot = -1;
	all->width_predot = 0;
	return(all);
}
