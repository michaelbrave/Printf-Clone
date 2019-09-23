/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:24 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:09:27 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     do_o(t_all *all) // converts to octal
{
    char *str;
    char *tmp;

    str = NULL;
    all->length = 6; //unsigned;
    str = length(all, str, 8);
    str = format_master(all, str);
    tmp = all->toprint;
    all->toprint = ft_strjoin(tmp, str);
    free(str);
    free(tmp);
    all->size = ft_strlen(all->toprint);

    return(0);
}