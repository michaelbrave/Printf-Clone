/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:08:31 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:08:51 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     do_c(t_all *all) // converts to char //gets called
{
    char *str;
    char *tmp;

    str = NULL;
    all->length = 2;
    str = length(all, str, 10);
    str = format_master(all, str);
    tmp = all->toprint;
    all->toprint = ft_strjoin(tmp, str);
    //free(str);
    //free(tmp);
    all->size = ft_strlen(all->toprint);
    return(0);
}
