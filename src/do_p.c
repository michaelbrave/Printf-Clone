/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:09:41 by mbrave            #+#    #+#             */
/*   Updated: 2019/09/07 15:09:43 by mbrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     do_p(t_all *all) // converts to pointer
{
    char *str;
    char *tmp;

    str = NULL;
    if (all->length == 0)
        all->length = 6;
    str = length(all, str, 16);
    str = format_master(all, str);
    str = ft_strjoin("0x", str); // do I need to capitolize ever?
    tmp = all->toprint;
    all->toprint = ft_strjoin(tmp, str);
    free(str);
    free(tmp);
    all->size = ft_strlen(all->toprint);
    return(0);
}